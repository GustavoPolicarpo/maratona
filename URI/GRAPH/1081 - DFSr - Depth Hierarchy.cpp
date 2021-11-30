// Author: Gustavo Policarpo
// Name: DFSr - Depth Hierarchy
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1081

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
#define MAXV 100001

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;
vector <int> adj[20];
int vis[20];

void dfs(int u, int e)
{
	if(vis[u]) return;
	vis[u]=1;
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		rep(z, 0, e) printf(" ");
		if(!vis[v]){
			cout << 
			u<<'-'<<v<<" pathR(G,"<<v<<")\n";
			dfs(v, e+2);
		}
		else{
			cout <<
			u<<'-'<<v<<"\n";
		}
		if(e==2 && i==adj[u].size()-1) cout << "\n";
	}	
}
int main()
{
	int N; cin >> N;
	rep(z, 1, N+1){
		printf("Caso %d:\n", z);
		int V, E;
			scanf("%d %d", &V, &E);
		rep(i, 0, V)
			adj[i].clear(), vis[i]=0;
		
		int u, v; set<ii>edge;
		rep(i, 0, E){
			scanf("%d %d", &u, &v);
			if(!edge.count(mp(u,v))) 
				adj[u].pb(v);
			edge.insert(mp(u,v));
		}
		rep(i, 0, E)
			sort(adj[i].begin(), adj[i].end());
		rep(i, 0, V){
			if(!vis[i]) dfs(i, 2);	
		}	
	}
return 0;
}
