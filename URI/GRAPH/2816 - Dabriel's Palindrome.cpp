// Author: Gustavo Policarpo
// Name: Dabriel's Palindrome
// Level: 8
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2816

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


vector <int> adj[100010];
map<char, int> mapa;
int vis[100010];
string s;

void dfs(int u){
	if(vis[u]) return; vis[u] = 1;
	mapa[s[u]]++;
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		dfs(v);
	}
}

int main(){
	
	int n, c; cin >> n >> c;
	cin >> s;
	
	int u, v;
	rep(i, 0, c){
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	rep(i, 0, n/2) adj[i].pb(n-i-1), adj[n-i-1].pb(i);
	
	int qt26 = 0;
	rep(i, 0, s.size()){
		if(!vis[i]){
			mapa.clear();
			dfs(i);
			if(mapa.size()>2){
				puts("0");
				return 0;
			}
			else if(mapa.size()==1 && mapa.count('*')){
				qt26++;
			}
			else if(mapa.size()==2 && !mapa.count('*')){
				puts("0");
				return 0;
			}
		}
	}
	
	ll ans = 1;
	rep(i, 0, qt26) ans = (ans*26)%1000000007;
	cout << ans << '\n';
			
	return 0;
}
