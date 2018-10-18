// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Six Flags
// Nível: 2
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1487

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

int N, T, dp[606], d, p, teste = 1, ans; 

int main(){
	
	while(scanf("%d %d", &N, &T) and N){
		rep(i, 0, T+2) dp[i] = -1; dp[0] = 0; ans = 0;
		rep(i, 0, N){
			scanf("%d %d", &d, &p);
			rep(j, d, T+1){
				if(dp[j-d]==-1) continue;
				dp[j] = max(dp[j], dp[j-d]+p);
				ans = max(ans, dp[j]);
			}
		}
		printf("Instancia %d\n%d\n\n", teste++, ans);
	}
	
	return 0;
}
