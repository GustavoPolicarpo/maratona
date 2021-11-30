// Author: Gustavo Policarpo
// Name: Noel and His Reindeer
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2934

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<ll, ll> ii;

int N, X[100010], dp[100010], dp1[1000010], dp2[1000010];

int main(){
	
	rep(i, 0, 1000001) dp1[i] = 0x3f3f3f3f, dp2[i] = -1;
	
	scanf("%d", &N);
	
	rep(i, 0, N){
		scanf("%d", &X[i]);
		dp1[X[i]] = min(X[i], dp1[X[i]-1]);
		dp[i] = dp1[X[i]];
		//cout << i << " " << dp[i] << '\n';
	}
	
	int ans = 0;
	
	for(int i=N-1; i>=0; i--){
		dp2[X[i]] = max(X[i], dp2[X[i]+1]);
		ans = max(ans, dp2[X[i]]-dp[i]+1+1);
		if(dp2[X[i]+2]!=-1) ans = max(ans, dp2[X[i]+2]-dp[i]+1);
	}
	
	cout << ans << '\n';
	

	
	
	return 0;
}
