

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int n;
int v[2002];
int dp[2002];

int sol(){
	for(int i=n-1; i>=0; i--){
		for(int j=i; j<n; j++){
			int timeSpend = i+n-1-j+1;
			dp[j] = max(dp[j]+v[i]*timeSpend, 
							dp[j-1]+v[j]*timeSpend);
		}
	}
	return dp[n-1];
}


int main(){
	
	cin >> n;
	rep(i, 0, n) cin >> v[i];
	cout << sol() << '\n';
	
	return 0;
} 
