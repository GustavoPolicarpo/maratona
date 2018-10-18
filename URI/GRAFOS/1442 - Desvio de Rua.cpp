// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Desvio de Rua
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1442

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;

#define INF 0x3f3f3f3f
const int mod=1e9+7;


#define MAXV 1010
vector<int> adj[MAXV], adj2[MAXV];
int dfs_num[MAXV], dfs_low[MAXV], dfs_parent[MAXV], vis[MAXV];
int dfscounter, V, dfsRoot, rootChildren, ans;
vector<ii> bridges;
bool yep;

void articulationPointAndBridge(int u){
	dfs_low[u] = dfs_num[u] = dfscounter++;
	rep(i,0,adj2[u].size()){
		int v = adj2[u][i];
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
int SCC[MAXV];
int dfsCounter, numSCC;
vector<int> S; //global variables

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsCounter++; //dfs_low[u] <= dfs_num[u]
	S.push_back(u); //stores u in a vector based on order of visitation
	vis[u] = 1;
	rep(i,0,adj[u].size()){
		int v = adj[u][i];
		if (dfs_num[v] == -1)
			tarjanSCC(v);
		if (vis[v]) //condition for update
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]){ //if this is a root (start) of an SCC
		while(42){
			int v = S.back(); S.pop_back();
			vis[v] = 0;
			SCC[v] = numSCC; //wich SCC this vertex belong
			if (u == v) break;
		}
		numSCC++;
	}
}

void dfs2(int u){
	if(vis[u]) return; vis[u]=1;
	rep(i, 0, adj2[u].size()) dfs2(adj2[u][i]);
	return;
}

int edg[1010][1010];
int main(){
	
	//freopen("in.txt", "r", stdin);
	
	int M;
	while(scanf("%d %d", &V, &M) !=EOF){
		
		rep(i,0,V+2){
			adj[i].clear();
			adj2[i].clear();
			rep(j, 0, V+2) edg[i][j]=0;
		}
		
		int u, v, t;
		rep(i, 0, M){
			scanf("%d %d %d", &u, &v, &t); u--, v--;
			if(i==0) continue;
			adj[u].pb(v);
			adj2[u].pb(v);
			adj2[v].pb(u);
			edg[u][v]=1;
			if(t==2) adj[v].pb(u), edg[v][u]=1;
		}
		
		yep=true;
		rep(i,0,V){
			dfs_num[i] = -1;
			dfs_low[i] = vis[i] = 0;
			SCC[i] = -i;
		}
		dfsCounter = numSCC = 0;
		rep(i,0,V){
			if(dfs_num[i] == -1)
				tarjanSCC(i);
		}
		if(numSCC==1){
			puts("-");
			continue;
		}
		
		yep=true; rep(i, 0, V+2) vis[i]=0;
		dfs2(0);
		rep(i, 0, V){
			if(!vis[i]){
				yep=false;
				break;
			}
			vis[i]=0;
		}
		if(!yep){
			puts("*");
			continue;
		}
		
		
		bridges.clear();
		dfscounter = 0;
		rep(i,0,V){
			dfs_low[i] = dfs_parent[i] = 0;
			dfs_num[i] = -1;
		}
		
		rep(i,0,V)
		if (dfs_num[i] == -1){
			dfsRoot = i; rootChildren = 0;
			articulationPointAndBridge(i);
		}
		
		yep=true;
		rep(i, 0, bridges.size()){
			u=bridges[i].F, v=bridges[i].S;
			if(edg[u][v]+edg[v][u]==1){
				yep=false;
				break;
			}
		}
		
		if(!yep) puts("2");
		else puts("1");
		
	}
	
		
	return 0;
	
}
