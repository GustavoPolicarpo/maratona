// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Imposto Real
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2666

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
typedef pair<ii, int> iii;

const ll mod = 1e9+7;

int N, C, mh = -1;
int cost[10010];
vector <ii> adj[10010];
vector <int> nivel[10010];
int pai[10010], dist[10010];

void dfs(int u, int last, int h){
	rep(i, 0, adj[u].size()){
		int v = adj[u][i].F,
			c = adj[u][i].S;
		if(v==last) continue;
		nivel[h].pb(v), pai[v] = u, dist[v] = c; mh = max(mh, h);
		dfs(v, u, h+1);
	}
}

int main(){
	
	scanf("%d %d", &N, &C);
	rep(i, 1, N+1) scanf("%d", &cost[i]);
	
	int u, v, c;
	rep(i, 1, N){
		scanf("%d %d %d", &u, &v, &c);
		adj[u].pb(ii(v, c));
		adj[v].pb(ii(u, c));
	}
	
	dfs(1, 1, 1);
	
	ll ans = 0;
	for(int i=mh; i>=1; i--){
		rep(j, 0, nivel[i].size()){
			u = nivel[i][j];
			ans += 2*((cost[u]+C-1)/C)*dist[u];
			cost[pai[u]]+=cost[u];
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
