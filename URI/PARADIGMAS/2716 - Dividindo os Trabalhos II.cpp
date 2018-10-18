// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Dividindo os Trabalhos II
// Nível: 6
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2716

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

int main(){
	
	int N;
	while(scanf("%d", &N)!=EOF){
		int X[N], sum = 0;
		rep(i, 0, N){
			scanf("%d", &X[i]);
			sum+=X[i];
		}
		int dp[sum+1];
		memset(dp, 0, sizeof dp); dp[0] = 1;
		rep(i, 0, N){
			for(int j=sum; j>=X[i]; j--)
				dp[j]|=dp[j-X[i]];
		}
		int ans = 0x3f3f3f3f;
		rep(i, 0, sum+1){
			if(dp[i]){
				ans = min(ans, abs(sum-i-i));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
