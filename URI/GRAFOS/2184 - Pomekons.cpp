// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pomekons
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2184

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
typedef pair<int, ii> iii;

#define INF 0x3f3f3f3f


vector <ii> adj[100010];
int h[100010], best[100010][24], pai[100010][24];
int N, K, Q;
ii n[5005];

void dfs(int u, int last){
	rep(i, 0, adj[u].size()){
		int v=adj[u][i].F,
			c=adj[u][i].S;
		if(v==last) continue;
		pai[v][0]=u, best[v][0]=c, h[v]=h[u]+1;
		rep(j, 1, 24) pai[v][j]=pai[pai[v][j-1]][j-1], best[v][j]=max(best[v][j-1], best[pai[v][j-1]][j-1]);
		dfs(v, u);
	}
}

ii LCA(int u, int v){
	if(h[u]<h[v]) swap(u, v);
	int uu=u, vv=v;
	ii ret=ii(0, 0);
	for(int i=23; i>=0; i--){
		if(h[pai[u][i]]>=h[v]){
			ret.F=max(ret.F, best[u][i]);
			u=pai[u][i];
		}
	}
	if(u==v){
		ret.S=h[uu]+h[vv]-2*h[u]+1;
		return ret;
	}
	
	for(int i=23; i>=0; i--){
		if(pai[u][i]!=pai[v][i]){
			ret.F=max(ret.F, max(best[u][i], best[v][i]));
			u=pai[u][i], v=pai[v][i];
		}
	}
	ret.F=max(ret.F, max(best[u][0], best[v][0]));
	u=pai[u][0], v=pai[v][0];
	ret.S=h[uu]+h[vv]-2*h[u]+1;
	return ret;
}

int pd[5005][1001];
int solve(int i, int k){
	if(i==Q) return 0;
	if(pd[i][k]!=-1) return pd[i][k];
	
	int ret=solve(i+1, k);
	if(k>=n[i].S) ret=max(ret, solve(i+1, k-n[i].S)+n[i].F);
	
	return pd[i][k]=ret;
}

int main(){
	
	scanf("%d %d", &N, &K);
	
	int u, v, c;
	rep(i, 1, N){
		scanf("%d %d %d", &u, &v, &c);
		adj[u].pb(ii(v, c));
		adj[v].pb(ii(u, c));
	}
	
	h[1]=1;
	dfs(1, 1);
	
	scanf("%d", &Q);
	rep(i, 0, Q){
		scanf("%d %d", &u, &v);
		n[i]=LCA(u, v);
	}
	
	memset(pd, -1, sizeof pd);
	int ans=solve(0, K); if(ans==0) ans=-1;
	printf("%d\n", ans);
	
	return 0;
}
