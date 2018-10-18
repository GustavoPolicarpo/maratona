// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Imperialismo
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1994

#define gc getchar
#define pc(x) putchar(x);
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

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}


vector <int> adj[10010];
int n, vis[10010][3], mdist, mid;

int bfs(int u, int op, int t=0){
	queue <ii> q;
	q.push(mp(u, t)); vis[u][op]=1;
	
	int ret=1;
	
	while(!q.empty()){
		u=q.front().F, t=q.front().S;  q.pop();
		mdist=t, ret=u;
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(vis[v][op]) continue;
			vis[v][op]=t+1;
			q.push(mp(v, t+1));
		}
	}
	
	return ret;
	
}

void dfs(int u, int last, int t){
	if(mid) return;
	if(t==(mdist+1)/2){
		mid=u;
		return;
	}
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(v==u) continue;
		dfs(v, u, t+1);
	}
	return;
}

int main()
{
	while(scanf("%d", &n) and n!=-1){
		rep(i, 1, n+1){
			adj[i].clear();
			vis[i][0]=vis[i][1]=vis[i][2]=0;
		}	mdist=0;
			mid=0;
		
		int u, v;
		rep(i, 1, n){
			scanf("%d", &u); v=i+1;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		int a=bfs(1, 0);
		int b=bfs(a, 1);
		dfs(a, 0, 0);
		bfs(mid, 2);
		
		printf("%d\n", mdist);
		
	}
	
	return 0;
	
}
