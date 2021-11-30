// Author: Gustavo Policarpo
// Name: Even Distribution
// Level: 10
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1747

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}
// 30, 42, 105, 70, 6, 3, 1, 2, 21, 7, 14

vector <int> adj[10010];
int N, M, num[10010];
set <int> ans, vis[10010];

void dfs(int u, int g){
	if(vis[u].count(g)) return;
	vis[u].insert(g), ans.insert(g);
	
	rep(i, 0, adj[u].size()){
		int v=adj[u][i],
			gg=__gcd(g, num[v]);
		dfs(v, gg);
	}
	return;
	
}
int main()
{
	int N, M; scanint(N), scanint(M);
	
	rep(i, 1, N+1) scanint(num[i]);
	int u, v;
	while(M--){
		scanint(u), scanint(v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	rep(i, 1, N+1) dfs(i, num[i]);
	
	printf("%d\n", ans.size());
	
	return 0;
	
}
