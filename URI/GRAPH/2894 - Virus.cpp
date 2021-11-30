// Author: Gustavo Policarpo
// Name: Virus
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2894

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

#define MAXV 1010
vector<int> adj[MAXV];
int dfs_num[MAXV], dfs_low[MAXV], dfs_parent[MAXV];
int dfscounter, dfsRoot, rootChildren;
int articulation[MAXV], articulations;
int vis[MAXV];
vector<ii> bridges;
map<ii, int> qt;

void articulationPointAndBridge(int u){
	dfs_low[u] = dfs_num[u] = dfscounter++;
	rep(i,0,adj[u].size()){
		int v = adj[u][i];
		if (dfs_num[v] == -1){
			dfs_parent[v] = u;
			if (u == dfsRoot) rootChildren++;
			articulationPointAndBridge(v);
			if(dfs_low[v] >= dfs_num[u]) articulation[u] = true;
			if (dfs_low[v] > dfs_num[u]) bridges.pb(ii(u,v));
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

set <ii> artic;
int ans;
int aux;

void sol(int u){
	if(vis[u]) return; vis[u] = 1, aux++;
	ans = max(ans, aux);
	rep(i, 0, adj[u].size()) sol(adj[u][i]);
}

void dfs(int u){
	if(vis[u]) return; vis[u] = 1;
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		if(artic.count(ii(u, v))){
			aux = 0;
			sol(v);
			continue;
		}
		dfs(v);
	}
}

void init(int n){
	dfscounter = 0; 
	rep(i,0,n){
		dfs_low[i] = dfs_parent[i] = articulation[i] = 0; 
		dfs_num[i] = -1; 
		vis[i] = 0;
		adj[i].clear();
	}
	articulations = 0; bridges.clear(); 
	qt.clear(); artic.clear(); ans = 0;
}

int main(){
	
	
	int T; scanf("%d", &T);
	while(T--){
		int N, M, C; scanf("%d %d %d", &N, &M, &C); C--;
		init(N);
		int u, v;
		rep(i, 0, M){
			scanf("%d %d", &u, &v);	u--, v--;
			adj[u].pb(v);
			adj[v].pb(u);
			qt[ii(u, v)]++;
			qt[ii(v, u)]++;
		}
		
		rep(i, 0, N){
			if (dfs_num[i] == -1){
				dfsRoot = i; rootChildren = 0; 
				articulationPointAndBridge(i); 
				articulation[dfsRoot] = (rootChildren > 1); 
			}
		} 
		
		/*printf("#articulations = %d\n",articulations); 
		rep(i,0,V) if(articulation[i]) 
			printf("Vertex %d\n", i); 
		*/
		
		//printf("#bridges = %d\n",bridges.size()); 
		
		rep(i,0,bridges.size()){
			if(qt[ii(bridges[i].F, bridges[i].S)] == 1){
				//printf("Bridge %d<->%d\n", bridges[i].F, bridges[i].S); 
				artic.insert(ii(bridges[i].F, bridges[i].S));
				artic.insert(ii(bridges[i].S, bridges[i].F));
			}
		}
		
		dfs(C);
		
		cout << ans << '\n';
		
	}

	return 0; 
}	
	

