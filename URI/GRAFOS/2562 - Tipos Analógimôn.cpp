// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tipos Analógimôn
// Nível: 2
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2562

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;

vector <int> adj[1010]; int vis[1010];

int dfs(int u){
	if(vis[u]) return 0; vis[u]=1; int ret=1;
	rep(i, 0, adj[u].size()) ret+=dfs(adj[u][i]);
	return ret;
}

int main(){
	
	int n, m;
	while(scanf("%d %d", &n, &m)!=EOF){
		
		rep(i, 0, n+2){
			vis[i]=0;
			adj[i].clear();
		}
		
		int u, v;
		rep(i, 0, m){
			scanf("%d %d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		scanf("%d", &u);
		
		printf("%d\n", dfs(u));
		
	}	
	
	return 0;
	
}
