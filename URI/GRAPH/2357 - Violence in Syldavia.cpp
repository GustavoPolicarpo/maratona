// Author: Gustavo Policarpo
// Name: Violence in Syldavia
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2357

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
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, M;
vector <int> adj[10010]; int vis[10010], yep;


void dfs(int u, int last){
	if(!yep || vis[u]) return;
	
	vis[u]=1;
	
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(v==last) continue;
		if(vis[v] == 1){
			yep=0;
			return;
		}
		dfs(v, u);
	}
	return;
}
int main()
{
	while(scanf("%d %d", &N, &M) !=EOF){
		rep(i, 1, N+1){
			vis[i]=0;
			adj[i].clear();
		}	yep=1;
		
		int u, v;
		while(M--){
			scanint(u), scanint(v);
			if(u==v) yep=0;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		if(!yep){
			puts("Inseguro");
			continue;
		}
		
		rep(i, 1, N+1){
			if(!vis[i]){
				dfs(i, i);
				if(!yep) break;
			}
		}
		
		yep ? puts("Seguro") : puts("Inseguro");
		
	}

	return 0;
	
}
