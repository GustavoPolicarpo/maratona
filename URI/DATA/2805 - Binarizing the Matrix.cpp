// Author: Gustavo Policarpo
// Name: Binarizing the Matrix
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2805

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n, m;
char mat[111][111];
ll pd[111][111][111];
int sum[111][111];

int query(int i, int j){
	int ret = sum[i][j];
	//if(i) ret-=sum[i-1][j];
	//if(j) ret-=sum[i][j-1];
	//if(i && j) ret+=sum[i-1][j-1];
	return ret;
}

int mod = 1e9+7;

ll solve(int i, int j, int k){
	if(i==-1) return 1;
	if(j<k) return solve(i-1, m-1, k);
	if(pd[i][j][k]!=-1) return pd[i][j][k];
	ll ret = 0; int qt = query(i, j);
	
	if(mat[i][j]=='0') ret = solve(i, j-1, k);
	else if(mat[i][j]=='1' && !qt) ret = solve(i-1, m-1, j+1);
	else if(mat[i][j]=='.'){
		ret = solve(i, j-1, k);
		if(!qt) ret += solve(i-1, m-1, j+1);
	}
	return pd[i][j][k] = ret%mod;
}


int main(){
	
	cin >> n >> m;
	rep(i, 0, n) rep(j, 0, m) cin >> mat[i][j];
	memset(pd, -1, sizeof pd);
	
	sum[0][0] = (mat[0][0]=='0');
	rep(j, 1, m) sum[0][j] = sum[0][j-1] + (mat[0][j]=='0');
	rep(i, 1, n) sum[i][0] = sum[i-1][0] + (mat[i][0]=='0');
	rep(i, 1, n) rep(j, 1, m) sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (mat[i][j]=='0');
		
	cout << solve(n-1, m-1, 0) << '\n';

	return 0;
}
