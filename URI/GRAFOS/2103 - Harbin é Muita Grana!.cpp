// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Harbin é Muita Grana!
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2103

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
#define mod 1300031
#define error 1e-7

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
int N, n[10001], dist[10001];
vector <ii> adj[10001];

void dfs(int u, int last){
	n[u] = 1;
	rep(i, 0, adj[u].size()){
		int v=adj[u][i].F;
		if(v==last) continue;
		dist[v]=adj[u][i].S;
		dfs(v, u);
		n[u]+=n[v];
	}
	return;
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T; scanint(T);
	while(T--){
		scanint(N);
		rep(i, 1, N+1){
			adj[i].clear();
			n[i]=0, dist[i]=0;
		}
	
		int u, v, c;
		rep(i, 1, N){
			scanint(u), scanint(v), scanint(c);
			adj[u].pb(mp(v, c));
			adj[v].pb(mp(u, c));
		}
		dfs(1, 1);
		ll out=0;
		rep(i, 2, N+1){
			out+=(dist[i]*(n[i])*(N-n[i]));
			if(out>=1300031) out%=mod;
		}
		printf("%lld\n", out);
	}
	
return 0;	
}
