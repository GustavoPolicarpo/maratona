// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Rodovia
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2429

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;
typedef pair < iii, ii > iiii;

const ll mod = 1e9;
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


int N, vis[2][10010];
vector <int> adj[2][10010];

void dfs(int l, int u){
	if(vis[l][u]) return;
	vis[l][u]=1;
	rep(i, 0, adj[l][u].size()){
		int v=adj[l][u][i];
		if(!vis[l][v])
			dfs(l, v);
	}
	return;
}

int main()
{	
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
	scanf("%d", &N);
	int u, v;
	rep(i, 0, N){
		scanf("%d %d", &u, &v);
		adj[0][u].pb(v);
		adj[1][v].pb(u);
	}
	
	dfs(0, 1);
	rep(i, 1, N+1){
		if(!vis[0][i]){
			puts("N");
			return 0;
		}
	}
	
	dfs(1, 1);
	rep(i, 1, N+1){
		if(!vis[1][i]){
			puts("N");
			return 0;
		}
	}
	
	puts("S");
	
	return 0;
	
}
