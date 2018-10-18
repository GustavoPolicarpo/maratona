// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Elias e Golias
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1592

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
#define mod 1300031
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, int > ii;
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

int N, M, K, pd[1001][1001];
vector <ii> adj[1001];

int solve(int u, int k){
	if(u==N-1) return 0;

	if(pd[u][k]!=-1) return pd[u][k];
	int ret=INF;
	rep(i, 0, adj[u].size()){
		if(k+1>K) continue;
		int v=adj[u][i].F;
		ret=min(ret, solve(v, k+1)+adj[u][i].S);
	}
	return pd[u][k]=ret;
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T; cin >> T;
	while(T--){
		scanf("%d %d %d", &N, &M, &K);
		int u, v, w;
		rep(i, 0, N){
			adj[i].clear();
			rep(j, 1, K+1) pd[i][j]=-1;
		}
		rep(i, 0, M){
			scanf("%d %d %d", &u, &v, &w);
			adj[u].pb(mp(v, w));
		}
		ll out=solve(0, 1);
		if(out==INF) out=-1;
		printf("%lld\n", out);
	}
	
return 0;	
}
