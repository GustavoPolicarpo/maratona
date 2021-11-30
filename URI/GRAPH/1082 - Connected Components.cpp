// Author: Gustavo Policarpo
// Name: Connected Components
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1082

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

using namespace std;

vector <int> adj[200];
int vis[200];
vector <char> out;

int dfs(int v){
	out.pb(v);
	vis[v]=1;
	rep(i, 0, adj[v].size()){
		int w=adj[v][i];
		if(vis[w]!=1)
			dfs(w);
	}
	
}


int main()
{
	int N; cin >> N;
	rep(a,1,N+1){
	
	
		int V, E;
		cin >> V >> E;
		
		rep(i, 'a', V+97){
			adj[i].clear();
			vis[i]=0;
		}
		
		while(E--){
			char u, v;
			cin >> u >> v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		cout << "Case #" << a << ':' << endl;
			
		int nc=0;
		rep(i, 'a', V+97)
			if(vis[i]==0){
				dfs(i);
				sort(out.begin(), out.end());
				rep(j,0,out.size())
					cout << out[j] << ',';
				out.clear();
				cout << endl;
				nc++;
			}
					
		cout << nc << " connected components" << endl;
		cout << endl;
	}
	
	
return 0;
}

