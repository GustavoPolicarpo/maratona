// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Chefe
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1469

#include<bits/stdc++.h>
#define gc getchar_unlocked


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
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

vector <int> adj[501];
int N, M, Q, idade[501], vis[501], id[501];

int dfs(int u){
	if(vis[u]) return INF;
	vis[u]=1;
	int ret=INF;
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		ret=min(ret, idade[v]);
		ret=min(ret, dfs(v));
	}
	return ret;
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(scanf("%d %d %d", &N, &M, &Q) !=EOF){ N++;
		rep(i, 1, N){
			scanf("%d", &idade[i]);
			id[i]=i;
			adj[i].clear();
		}
		int u, v;
		rep(i, 0, M){
			scanf("%d %d", &u, &v);
			adj[v].pb(u);
		}
		char op;
		while(Q--){
			scanf(" %c", &op);
			if(op=='P'){
				scanf("%d", &u);
				rep(i, 1, N) vis[i]=0;
				int ans=dfs(id[u]);
				if(ans==INF) printf("*\n");
				else printf("%d\n", ans);	
			}
					
			else{
				scanf("%d %d", &u, &v);
				swap(idade[id[u]], idade[id[v]]);
				swap(id[u], id[v]);
			}
		}
	}
	
return 0;	
}
