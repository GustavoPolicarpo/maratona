// Author: Gustavo Policarpo
// Name: Improve SPAM
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3020

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define REP(i,a,b) for( int i = (int) a; i <= (int) b; i++ )
#define PER(i,a,b) for( int i = (int) a; i >= (int) b; i-- )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
 
using namespace std;
 
typedef long long int ll;
typedef pair <int, int> ii;
const int MAX = 2e3+3;
const int MOD = 1e9+7;
vector<int> adj[MAX];
int N, M, k, x;
int ans, pd[MAX];
int vis[MAX];

int solve(int u) {
	if(u > M && !vis[u]) ans++;
	vis[u] = 1;
	if(pd[u] != -1) return pd[u];
	pd[u] = 0;
	for(auto v : adj[u])
		pd[u] = (pd[u]+solve(v)) % MOD;
	return pd[u];
}

int main(){
	scanf("%d%d",&N, &M);
	REP(i, 1, M) pd[i] = -1;
	REP(i, M+1, N) pd[i] = 1;
	REP(i, 1, M) {
		scanf("%d", &k);
		rep(j, 0, k) {
			scanf("%d", &x);
			adj[i].pb(x);
		}
	}
	int a = solve(1);
	printf("%d %d\n", a, ans);
	return 0;
}
