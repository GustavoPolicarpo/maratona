// Author: Gustavo Policarpo
// Name: Sequência
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2837

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
 

int N, L, H, dp[100010][22], s[100010], m[100010], ans = -0x3f3f3f3f;

int main(){
	
	scanf("%d %d %d", &N, &L, &H);
	rep(i, 0, N+2) rep(j, 0, H+2) dp[i][j] = -0x3f3f3f3f;
	
	rep(i, 0, N) scanf("%d", &s[i]);
	rep(i, 0, N) scanf("%d", &m[i]);
	
	dp[N][0] = 0;
	for(int i=N-1; i>=0; i--){
		dp[i][m[i]] = s[i];
		rep(j, 0, 21){
			dp[i][j+m[i]] = max(dp[i+1][j]+s[i], dp[i][j+m[i]]);
		}
		rep(j, L, H+1) ans = max(ans, dp[i][j]);
	}
	
	printf("%d\n", ans);
	

	
	return 0;
}  
