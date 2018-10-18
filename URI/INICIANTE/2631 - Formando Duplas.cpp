// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Formando Duplas
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2631

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

int N, M, Q;
vector <int> adj[10010];
int compo[10010];

void dfs(int u, int c){
	if(compo[u]) return; compo[u] = c;
	rep(i, 0, adj[u].size()) dfs(adj[u][i], c);
	return;
}

int main(){
	
	int ye = 0;
	while(scanf("%d %d %d", &N, &M, &Q) !=EOF){
		
		rep(i, 1, N+1) adj[i].clear(), compo[i] = 0;
		int u, v; while(M--){
			scanf("%d %d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		int cnt = 1;
		rep(i, 1, N+1) if(!compo[i]) dfs(i, cnt++);
		
		ye ? printf("\n") : ye = 1;
		while(Q--){
			scanf("%d %d", &u, &v);
			puts( (compo[u] == compo[v]) ? "S" : "N" );
		}
	}

		
	return 0;
}
