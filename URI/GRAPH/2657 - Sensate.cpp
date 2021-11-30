// Author: Gustavo Policarpo
// Name: Sensate
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2657

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


struct use{
	string name;
	int val;
};

vector <int> v[10010];
vector <int> adj[10010];
int cnt = 0, cnt2=1, vis[10010];
map<string, int> mapa;
int C[10010];

void dfs(int u, int c){
	if(vis[u]) return; vis[u] = c, v[c].pb(u);
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		dfs(v, c);
	}
}

bool cmp(int a, int b){
	return C[a]>C[b];
}

int main(){
	
	int N, M, Q; scanf("%d %d %d", &N, &M, &Q); string s; int aux;
	
	rep(i, 0, N){
		cin >> s >> aux;
		mapa[s] = cnt++;
		C[cnt-1] = aux;
	}
	
	string a, b;
	while(M--){
		cin >> a >> b;
		adj[mapa[a]].pb(mapa[b]);
		adj[mapa[b]].pb(mapa[a]);
	}
	
	rep(i, 0, cnt){
		if(!vis[i]){
			dfs(i, cnt2++);
		}
	}
	
	rep(i, 1, cnt2) sort(v[i].begin(), v[i].end(), cmp);
	
	while(Q--){
		cin >> s; aux = vis[mapa[s]];
		if(v[aux].size()==1 || C[mapa[s]]>=5 || C[v[aux][0]]<=5) puts("S");
		else puts("N");	
	}	
	
	return 0;
}
