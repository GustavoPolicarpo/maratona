// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Crise Hídrica
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2789

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

int N, D, M, Q, custo[5050], valor[5050], u, v, c;
vector <int> adj[5050];
int pai[5050][24], level[5050];
ll dp[1010], ans;

void dfs(int u, int last){
	rep(i, 0, adj[u].size()){
		int v = adj[u][i]; if(v==last) continue;
		pai[v][0] = u, level[v] = level[u]+1;
		rep(j, 1, 24) pai[v][j] = pai[pai[v][j-1]][j-1];
		dfs(v, u);
	}
}

int LCA(int a, int b){
	if(a==b) return a;
	if(level[a]<level[b]) swap(a, b);
	for(int i=23; i>=0; i--){
		if(level[pai[a][i]]>=level[b]){
			a = pai[a][i];
		}
	}
	if(a==b) return a;
	for(int i=23; i>=0; i--){
		if(pai[a][i]!=pai[b][i]){
			a = pai[a][i], b = pai[b][i];
		}
	}
	return pai[a][0];
}

void dfs2(int u, int last){
	rep(i, 0, adj[u].size()){
		int v = adj[u][i]; if(v==last) continue;
		dfs2(v, u);
		valor[u]+=valor[v];
	}
}

int main(){
	
	scanf("%d %d", &N, &D);
	rep(i, 1, N){
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	rep(i, 0, 24) pai[1][i] = 1; level[1] = 1;
	dfs(1, 1);
	
	memset(custo, 0x3f3f3f3f, sizeof custo);
	scanf("%d", &M);
	rep(i, 0, M){
		scanf("%d %d", &u, &c);
		custo[u] = c;
	}
	
	scanf("%d", &Q)	;
	rep(i, 0, Q){
		scanf("%d %d %d", &u, &v, &c);
		int lca = LCA(u, v);
		valor[u]+=c, valor[v]+=c;
		valor[lca]-=c, valor[pai[lca][0]]-=c;
	}
	
	dfs2(1, 1);
	
	memset(dp, -1, sizeof dp); dp[0] = 0;
	rep(i, 1, N+1){
		for(int j=D; j>=custo[i]; j--){
			if(dp[j-custo[i]]==-1) continue;
			dp[j] = max(dp[j], dp[j-custo[i]]+valor[i]);
			ans = max(ans, dp[j]);
		}
	}
	
	cout << ans << '\n';
	
	return 0;
}
