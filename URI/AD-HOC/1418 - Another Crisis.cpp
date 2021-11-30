// Author: Gustavo Policarpo
// Name: Another Crisis
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1418

#include <bits/stdc++.h>

// boca-submit-run teammgmu19 GGZBKdXEx PP C++14 FF

#define rep(i, a, b) for(int i = a; i < b; i++)
#define REP(i, a, b) rep(i, a, b+1)
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a, b) cout << #a << " = "  << a << " ---- " << #b << " = " << b << endl;
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int N, T;
vector <int> adj[100010];
int sz[100010];
int cf[100010];

void dfs(int u){
	if(!adj[u].size()){
		cf[u] = 1;
		return;
	}
	
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		dfs(v);
	}
	
	vector <ii> aux;
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		aux.pb(ii(cf[v], v));
	}
	
	sort(aux.begin(), aux.end());
	
	int nd = (T*adj[u].size()+99)/100;
	int c = 0;
	rep(i, 0, nd){
		c += aux[i].F;		
	}
	
	cf[u] = c;
}

int main(){
	
	while(scanf("%d %d", &N, &T) and N){
		rep(i, 0, N+1){
			adj[i].clear();
			sz[i] = 1;
		}
		int u;
		rep(i, 1, N+1){
			scanf("%d", &u);
			adj[u].pb(i);
		}
		dfs(0);
		
		printf("%d\n", cf[0]);
		
	}
	return 0;
}
