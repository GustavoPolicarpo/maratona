// Author: Gustavo Policarpo
// Name: Campaign's Promise
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1835

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

using namespace std;

vector <int> adj[200];
int vis[200];

int dfs(int v){
	vis[v]=1;
	rep(i,0,adj[v].size()){
		int w=adj[v][i];
		if(vis[w]!=1)
			dfs(w);
	}
}

int main()
{
	int T; cin >> T;
    rep(z,1,T+1)
	{
		int N, M;
		cin >> N >> M;
		
		rep(i,1,N+1){
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
		
		rep(i,1,N+1){
			if(vis[i]==0){
				ne++;
				dfs(i);
			}	
		}
		cout << "Caso #" << z << ": ";
		if(ne==0)
			cout << "a promessa foi cumprida";
		else
			cout << "ainda falta(m) " << ne << " estrada(s)";
		cout << endl;		
	}		
return 0;
}

