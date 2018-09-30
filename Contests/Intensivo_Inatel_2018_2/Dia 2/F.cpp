#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int K, N, mod = 1000000;
int pd[101][101];

int solve(int k, int n){
	if(n>N) return 0;
	if(k==K) return (n==N);
	if(pd[k][n]!=-1) return pd[k][n];
	int ret = 0;
	rep(i, 0, N+1)
		ret = (ret+solve(k+1, n+i))%mod;
	return pd[k][n] = ret;
}

int main(){
	
	while(cin >> N >> K and N){
		memset(pd, -1, sizeof pd);
		cout << solve(0, 0) << '\n';
	}
	
	return 0;
} 
