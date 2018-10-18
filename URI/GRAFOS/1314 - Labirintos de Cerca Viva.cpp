// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Labirintos de Cerca Viva
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1314

#include<bits/stdc++.h>

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned long long int ull;
typedef pair < int, ll > ii;
typedef pair < double, int > iii;

#define MAXV 10010
vector<int> adj[MAXV];
int dfs_num[MAXV], dfs_low[MAXV], dfs_parent[MAXV];
int dfscounter, V, dfsRoot, rootChildren;
vector <ii> bridges;

void articulationPointAndBridge(int u){
	dfs_low[u] = dfs_num[u] = dfscounter++;
	
	rep(i,0,adj[u].size()){
		int v = adj[u][i];
		if (dfs_num[v] == -1){
			dfs_parent[v] = u;
			if (u == dfsRoot) rootChildren++;

			articulationPointAndBridge(v);
			if (dfs_low[v] > dfs_num[u]) bridges.pb(mp(u,v));

			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
		}
		else if (v != dfs_parent[u])
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int pset[MAXV];
int findset(int x){
	if(pset[x]!=x) pset[x]=findset(pset[x]);
	return pset[x];
}
bool unionset(int x, int y){
	x=findset(x), y=findset(y);
	pset[x]=y;
}
bool sameset(int x, int y){
	return findset(x)==findset(y);
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int M, Q;
	
	while(scanf("%d %d %d", &V, &M, &Q) and V+M){
		
		dfscounter = 0;
		rep(i,1,V+1){
			dfs_low[i] = dfs_parent[i] = 0;
			dfs_num[i] = -1;
			adj[i].clear();
			pset[i]=i;
		}
		bridges.clear();
		
		int u, v;
		rep(i, 0, M){
			scanf("%d %d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		rep(i,1,V+1)
		if (dfs_num[i] == -1){
			dfsRoot = i; rootChildren = 0;
			articulationPointAndBridge(i);
		}
		
		rep(i, 0, bridges.size()){
			u=bridges[i].F, v=bridges[i].S;
			if(!sameset(u, v))
				unionset(u, v);
		}
		while(Q--){
			scanf("%d %d", &u, &v);
			puts( findset(u)==findset(v) ? "Y" : "N" );
		}
		
		puts("-");
			
		/*printf("#bridges = %d\n",bridges.size());
		rep(i,0,bridges.size())
			printf("Bridge %d<->%d\n", bridges[i].F, bridges[i].S);*/
	}
	
	return 0;
	
}
