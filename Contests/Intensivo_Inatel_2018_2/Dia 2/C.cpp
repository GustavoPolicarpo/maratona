#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int pd[101][101*501], n, v[101];
int solve(int i, int d){
	if(i==n) return d;
	if(pd[i][d]!=-1) return pd[i][d];
	int ret = min(solve(i+1, d+v[i]), solve(i+1, abs(d-v[i])));
	return pd[i][d] = ret;
}

int main(){

	int T; cin >> T;
	while(T--){
		cin >> n;
		rep(i, 0, n) cin >> v[i];
		memset(pd, -1, sizeof pd);
		printf("%d\n", solve(0, 0));
	}
	
	return 0;
} 
