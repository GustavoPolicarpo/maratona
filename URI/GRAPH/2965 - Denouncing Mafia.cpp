// Author: Gustavo Policarpo
// Name: Denouncing Mafia
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2965

#include <bits/stdc++.h>

// boca-submit-run teammgmu19 GGZBKdXEx PP C++14 FF

#define rep(i, a, b) for(int i = a; i < b; i++)
#define REP(i, a, b) rep(i, a, b+1)
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a, b) cout << #a << " = "  << a << " ---- " << #b << " = " << b << endl;
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int N, K;
vector <int> adj[100010];
ii h[100010];
int val[100010];
int vis[100010];

void dfs(int u, int last){
	h[u].F = 1;
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		if(v==last) continue;
		dfs(v, u);
		h[u].F = max(h[u].F, h[v].F+1);
	}
	val[u] = h[u].F;
	return;
}

void fill(int u){
	vis[u] = 1;
	int id = -1, mx = 0;
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		if(vis[v]) continue;
		if(val[v] > mx){
			mx = val[v];
			id = i;
		}
	}
	if(id!=-1){
		fill(adj[u][id]);
	}
}

int main(){
	
	int u;
	scanf("%d %d", &N, &K);
	rep(i, 2, N+1){
		scanf("%d", &u);
		adj[u].pb(i);
		adj[i].pb(u);
	}

	rep(i, 1, N+1) h[i].S = i; 
	dfs(1, 1);
	
	sort(h+1, h+N+1);
	reverse(h+1, h+N+1);
	
	ll ans = 0;
	rep(i, 1, N+1){
		if(!K) break;
		if(!vis[h[i].S]){
			ans += h[i].F;
			fill(h[i].S);
			K--;
		}
	}
	
	printf("%lld\n", ans);
		
	return 0;
}
