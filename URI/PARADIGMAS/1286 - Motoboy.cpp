// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Motoboy
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1286

#pragma comment(linker, "/stack:200000000")                                     
#pragma GCC optimize("Ofast")                                                   
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")   
#define _CRT_SECURE_NO_WARNINGS          
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;



int main(){
	
	int N, P;
	while(cin >> N >> P){
		if(!N) break;
		int custo[N], valor[N];
		rep(i, 0, N) cin >> valor[i] >> custo[i];
		int dp[P+1];
		memset(dp, -1, sizeof dp);
		dp[0] = 0;
		for(int i=0; i<N; i++){
			for(int j=P; j>=custo[i]; j--){
				if(dp[j-custo[i]]==-1) continue;
				dp[j] = max(dp[j], dp[j-custo[i]]+valor[i]);
			}
		}
		
		int ans = 0;
		rep(i, 0, P+1) ans = max(ans, dp[i]);
		printf("%d min.\n", ans);
		
	}

		
	return 0;
}
