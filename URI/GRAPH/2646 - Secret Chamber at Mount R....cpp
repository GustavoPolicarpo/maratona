// Author: Gustavo Policarpo
// Name: Secret Chamber at Mount R...
// Level: 4
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2646

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef long long int ll;
typedef pair <int, int>  ii;



vector <int> adj[26];
int vis[26];

void dfs(int u){
	if(vis[u]) return; vis[u] = 1;
	rep(i, 0, adj[u].size()) dfs(adj[u][i]);
	return;	
}

int main(){

	int n, m; cin >> n >> m;
	string a, b;
	
	rep(i, 0, n){
		cin >> a >> b;
		adj[a[0]-'a'].pb(b[0]-'a');
	}
	
	while(m--){
		cin >> a >> b;
		if(a.size()!=b.size()){
			puts("no");
			continue;
		}
		
		bool yep = true;
		rep(i, 0, a.size()){
			memset(vis, 0, sizeof vis);
			dfs(a[i]-'a');
			if(!vis[b[i]-'a']){
				yep = false;
				break;
			}
		}
		
		yep ? puts("yes") : puts("no");
	}
		
	return 0;
}
