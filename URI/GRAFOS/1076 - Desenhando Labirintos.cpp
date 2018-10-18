// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Desenhando Labirintos
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1076

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

using namespace std;

vector <int> adj[1000];
int vis[1000];

int dfs(int v, int &ne){
	ne++;
	vis[v]=1;
	rep(i,0,adj[v].size()){
		int w=adj[v][i];
		if(vis[w]!=1)
			dfs(w, ne);
	}
}

int main()
{
	int T; cin >> T;
    while(T--)
	{
		int bg; cin >> bg;
		int N, M;
		cin >> N >> M;
		rep(i,0,N+1){
			adj[i].clear();
			vis[i]=0;	
		} 
			
		while(M--){
			int u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		int ne=-1;
		
		dfs(bg, ne);
		ne*=2;
		cout << ne << endl;		
	}
			
return 0;
}

