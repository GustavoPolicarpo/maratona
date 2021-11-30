// Author: Gustavo Policarpo
// Name: The Bottom of a Graph
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1677

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
typedef pair<int, ii> iii;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;


#define MAXV 5050

int dfs_num[MAXV], dfs_low[MAXV], SCC[MAXV], vis[MAXV], V, G;
int dfsCounter, numSCC;
bool yep[MAXV];
vector<int> S, adj[MAXV]; //global variables

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
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d", &V) and V){
		
		rep(i,0,V){
			dfs_num[i] = -1;
			dfs_low[i] = vis[i] = 0;
			SCC[i] = -i;
			adj[i].clear();
			yep[i]=true;
		}	S.clear();
		
		scanf("%d", &G);
		
		int u, v;
		while(G--){
			scanf("%d %d", &u, &v); u--, v--;
			adj[u].pb(v);
		}
		
		dfsCounter = numSCC = 0;
		rep(i,0,V)
			if(dfs_num[i] == -1)
				tarjanSCC(i);
				
		vector <int> ans;
		
		rep(u, 0, V){
			if(!yep[SCC[u]]) continue;
			rep(i, 0, adj[u].size()){
				int v=adj[u][i];
				if(SCC[v]!=SCC[u]){
					yep[SCC[u]]=false;
					break;
				}
			}
		}
		
		rep(i, 0, V) if(yep[SCC[i]]) ans.pb(i+1);
		
		rep(i, 0, ans.size()){
			if(i) printf(" ");
			printf("%d", ans[i]);
		}	printf("\n");
		
				
	}
		
	return 0;
	
}
