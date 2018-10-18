// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Linhas de Metrô
// Nível: 2
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2887

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int level[100010], pai[100010][24];
vector <int> adj[100010];
int N, Q;

void dfs(int u, int last){
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		if(v==last) continue;
		pai[v][0] = u, level[v] = level[u]+1;
		rep(j, 1, 24) pai[v][j] = pai[pai[v][j-1]][j-1];
		dfs(v, u);
	}
}

int lca(int a, int b){
	if(level[a]<level[b]) swap(a, b);
	for(int i=23; i>=0; i--){
		if(level[pai[a][i]]>=level[b])
			a = pai[a][i];
	}
	if(a==b) return a;
	for(int i=23; i>=0; i--){
		if(pai[a][i]!=pai[b][i])
			a = pai[a][i], b = pai[b][i];
	}
	return pai[a][0];
}

int dist(int a, int b){
	int ab = lca(a, b);
	//cout << a << " " << b << " " << ab << " " << level[a] << " " << level[b] << '\n';
	return level[a] + level[b] - 2*level[ab];
}

int main(){
	
	int a, b, c, d;
	scanf("%d %d", &N, &Q);
	rep(i, 1, N){
		scanf("%d %d", &a, &b);
		adj[a].pb(b); adj[b].pb(a);
	}
	
	level[1] = 1;
	rep(i, 0, 24) pai[1][i] = 0;
	dfs(1, 1);
	
	while(Q--){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		int x = dist(a, b) + dist(c, d);
		int y = min(dist(a, c)+dist(b, d), dist(a, d)+dist(b, c));
		if(x<y) printf("%d\n", 0);
		else printf("%d\n", (x-y)/2+1);
	}
	
	return 0;
} 
