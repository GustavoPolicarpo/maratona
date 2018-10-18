// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Juntando Casais
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1302

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
typedef pair<ii, int> iii;

const ll mod = 1e9+7;

#define MAXV 100010
vector<int> adj[MAXV], adj2[MAXV], adj3[MAXV], adj4[MAXV];
int dfs_num[MAXV], dfs_low[MAXV], vis[MAXV], SCC[MAXV], compo[MAXV], tam[MAXV], order[MAXV];
int pai[MAXV][22], pai2[MAXV], h[MAXV], edg[MAXV];
int dfsCounter, numSCC, numComp;
vector<int> S;

void tarjanSCC(int u){
	dfs_low[u] = dfs_num[u] = dfsCounter++; 
	S.push_back(u); vis[u] = 1;
	rep(i,0,adj[u].size()){
		int v = adj[u][i];
		if (dfs_num[v] == -1)
			tarjanSCC(v);
		if (vis[v]) 
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}
	if (dfs_low[u] == dfs_num[u]){ 
		while(42){
			int v = S.back(); S.pop_back();
			vis[v] = 0;
			SCC[v] = numSCC; 
			if (u == v) break;
		}
		numSCC++;
	}
}

void dfs_lca(int u, int last){
	rep(i, 0, adj3[u].size()){
		int v=adj3[u][i];
		if(v==last) continue;
		h[v] = h[u]+1, pai[v][0] = u;
		rep(j, 1, 22) pai[v][j] = pai[pai[v][j-1]][j-1];
		dfs_lca(v, u);
	}
}

int get_circle(int u, int v){
	int a=order[u], b=order[v];
	if(a>b) swap(a, b);
	return min(b-a, tam[SCC[u]]-b+a);
}

int solve(int u, int v){
	if(u==v) return 0;
	if(compo[u]!=compo[v]) return -1;
	
	if(h[SCC[u]] < h[SCC[v]]) swap(u, v);
	int a=SCC[u], b=SCC[v];
	
	if(a==b) return get_circle(u, v);
	
	for(int i=21; i>=0; i--) if(h[pai[a][i]]>=h[b] && h[pai[a][i]]>0) a=pai[a][i];
	
	if(a==b) return h[SCC[u]]+h[SCC[v]]-2*h[a];
	if(h[b]==0) return h[SCC[u]]+get_circle(edg[a], v);
	
	for(int i=21; i>=0; i--) if(pai[a][i]!=pai[b][i] && pai[a][i]!=-1 && pai[b][i]!=-1) a=pai[a][i], b=pai[b][i];
	
	int lca=pai[a][0];
	
	if(h[lca]!=0) return h[SCC[u]]+h[SCC[v]]-2*h[lca];
	return h[SCC[u]]+h[SCC[v]]+get_circle(edg[a], edg[b]);
}

void dfs(int u, int c){
	if(compo[u]!=-1) return; compo[u] = c;
	rep(i, 0, adj2[u].size()) dfs(adj2[u][i], c);
}

void dfs_order(int u, int c){
	if(order[u]) return; order[u] = c;
	rep(i, 0, adj4[u].size()) dfs_order(adj4[u][i], c+1);
}

int main(){

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N;
	
	while(scanf("%d", &N) !=EOF){
		
		rep(i, 0, N+2){
			rep(j, 0, 22) pai[i][j] = -1;
			dfs_num[i] = compo[i] = edg[i] = -1;
			dfs_low[i] = vis[i] = tam[i] = h[i] = order[i] = 0;
			SCC[i] = -i;
			adj[i].clear(), adj2[i].clear(), adj3[i].clear(), adj4[i].clear();
		}	dfsCounter = numSCC = numComp = 0;
		
		int u, v;
		rep(u, 1, N+1){
			scanf("%d", &v);
			adj[u].pb(v);
			adj2[u].pb(v);
			adj2[v].pb(u);
		}
		
		rep(i, 1, N+1) if(dfs_num[i]==-1) tarjanSCC(i);
		rep(i, 1, N+1) if(compo[i]==-1) dfs(i, numComp++);
		rep(i, 1, N+1) tam[SCC[i]]++;
		
		rep(i, 1, N+1){ 
			u=SCC[i], v=SCC[adj[i][0]];
			if(u==v){
				adj4[i].pb(adj[i][0]);
				adj4[adj[i][0]].pb(i);
				continue;
			}
			if(tam[u]>1) edg[v]=i;
			if(tam[v]>1) edg[u]=adj[i][0];
			adj3[u].pb(v);
			adj3[v].pb(u);
		}
		
		rep(i, 0, numSCC) if(tam[i] > 1) dfs_lca(i, i);
		rep(i, 1, N+1) if(!order[i]) dfs_order(i, 1);
		//rep(i, 1, N+1) cout <<  i << " " << SCC[i] << " " << compo[i] << " " << edg[SCC[i]] << '\n';
		
		int Q; scanf("%d", &Q);
		
		while(Q--){
			scanf("%d %d", &u, &v);
			printf("%d\n", solve(u, v));
		}
	}
	
	return 0;	
}
