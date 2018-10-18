// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Árvore Genealógica
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2854

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;

map<string, int> mapa;
vector <int> adj[303];
int vis[303], cnt = 0;

void dfs(int u){
	if(vis[u]) return; vis[u] = 1;
	rep(i, 0, adj[u].size()) dfs(adj[u][i]);
	return;
}

int main(){
    
    int n, m; cin >> n >> m;
    string a, b, c;
    rep(i, 0, m){
    	cin >> a >> b >> c;
    	if(!mapa.count(a)) mapa[a] = cnt++;
    	if(!mapa.count(c)) mapa[c] = cnt++;
    	adj[mapa[a]].pb(mapa[c]);
    	adj[mapa[c]].pb(mapa[a]);
	}
	
	int ans = 0;
	rep(i, 0, cnt){
		if(!vis[i]){
			dfs(i);
			ans++;
		}
	}
	
	cout << ans << '\n';
	
    return 0;
}  
