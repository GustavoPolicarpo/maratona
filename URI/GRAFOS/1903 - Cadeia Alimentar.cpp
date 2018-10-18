// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cadeia Alimentar
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1903

#include <bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void scanint(int &x){
    register int ccc = gc(); x = 0; int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;

#define MAXV 100010

vector<int> adj[MAXV], adj2[MAXV]; int N, M;
int dfs_num[MAXV], dfs_low[MAXV], vis[MAXV], SCC[MAXV], grau[MAXV];
set <ii> st;
int dfsCounter, numSCC;
vector<int> S; //global variables
vector <int> edg[MAXV];

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

int main(){
	
	ios_base::sync_with_stdio(false);
	
	cin >> N >> M; int u, v;
	rep(i, 0, M){
		cin >> u >> v; u--, v--;
		adj[u].pb(v);
	}
	
	rep(i, 0, N+2){
		dfs_num[i] = -1;
		dfs_low[i] = vis[i] = 0;
		SCC[i] = -i;
	}
	
	dfsCounter = numSCC = 0;
	rep(i, 0, N)
		if(dfs_num[i] == -1)
			tarjanSCC(i);
	
	rep(i, 0, N){
		dfs_num[i]=0;
		vis[i]=0;
	}
	rep(i, 0, N) edg[SCC[i]].pb(i), dfs_num[SCC[i]]=1, st.insert(ii(i, i));
	
	rep(i, 0, N){
		rep(j, 0, edg[i].size()){
			int u=edg[i][j];
			rep(k, 0, adj[u].size()){
				int v=adj[u][k];
				int uu=SCC[u], vv=SCC[v];
				if(!st.count(ii(uu, vv))){
					st.insert(ii(uu, vv));
					adj2[uu].pb(vv);
					grau[vv]++;	
				}
			}
		}
	}
	
	int yep=true;
	queue <int> q;
	rep(i, 0, N) if(dfs_num[i] && grau[i]==0 && !vis[i]) vis[i]=1, q.push(i);
	
	while(!q.empty()){
		if(q.size()>1) yep=false;
		int u=q.front(); q.pop(); vis[u]=1;
		rep(i, 0, adj2[u].size()){
			int v=adj2[u][i];
			grau[v]--;
			if(!grau[v]) q.push(v);
		}
	}
	
	rep(i, 0, N) if(dfs_num[i] && !vis[i]) yep=false;
	
	yep? puts("Bolada") : puts("Nao Bolada");
	
	return 0;
}
