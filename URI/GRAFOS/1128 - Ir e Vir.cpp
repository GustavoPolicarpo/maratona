// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ir e Vir
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1128

#define gc getchar_unlocked
#include<bits/stdc++.h>

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
const int mod = 1e9 + 7;
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
//typedef pair < int, int > ii;
//typedef pair < int, ii > iii;

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

const int MAX=2002;
vector <int> adj[MAX]; int vis[MAX];
int N, M;

void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(!vis[v]){
			dfs(v);
		}
	}
	return;
}
int main()
{
	while(scanf("%d %d", &N, &M) and N+M){
		rep(i, 1, N+1){ //for(int i=1; i<N+1; i++)
			adj[i].clear();
			vis[i]=0;
		}
		
		int u, v, t;
		rep(i, 0, M){
			scanf("%d %d %d", &u, &v, &t);
			adj[u].pb(v);
			if(t==2)
				adj[v].pb(u);
		}
		
		bool did=true;
		rep(i, 1, N+1){
			dfs(i);
			rep(j, 1, N+1){
				if(!vis[j]){
					did=false;
					break;
				}
				vis[j]=0;
			}
			if(!did){
				break;
			}
		}
		
		if(did)	printf("1\n");
		else printf("0\n");
	}
	
return 0;
}
