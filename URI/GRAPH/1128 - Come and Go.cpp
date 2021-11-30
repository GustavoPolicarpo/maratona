// Author: Gustavo Policarpo
// Name: Come and Go
// Level: 4
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1128

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

using namespace std;

vector <int> adj[2001];
int vis[2001];

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
	int N, M;
	while(cin >> N >> M && N+M)	
	{
		rep(i,1,N+1)
			adj[i].clear();
		
		
			
		rep(i,0,M){
			int u, v, p;
			cin >> u >> v >> p;
			adj[u].pb(v);
			if(p==2)
				adj[v].pb(u);	
		}
		/*cout << endl;
		rep(i,0,M){
			rep(j,0,adj[i].size()){
				cout << i << " " << adj[i][j] << " ";
			}
			cout << endl;
		}*/
			
		bool did=true;
		rep(i,1,N+1){
			memset(vis,0,sizeof(vis));
			dfs(i);
			rep(j,1,N+1)
				if(vis[j]==0)
				{
					did=false;
					break;			
				}
			if(did==false)
				break;	
		}
		
		if(did==false)
			cout << 0;
		else
			cout << 1;
		cout << endl;
		
		
	}
		
return 0;
}

