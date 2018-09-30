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
int pd[2002][2002];

int solve(int i, int j, int a){
	if(i>j) return 0;
	if(pd[i][j]!=-1) return pd[i][j];
	int ret = max(solve(i+1, j, a+1)+v[i]*a, solve(i, j-1, a+1)+v[j]*a);
	return pd[i][j] = ret;
}


int main(){
	
	cin >> n;
	rep(i, 0, n) cin >> v[i];
	memset(pd, -1, sizeof pd);
	cout << solve(0, n-1, 1) << '\n';
	
	return 0;
} 
