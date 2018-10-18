// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Mapa
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2468

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

const int MAXN=100010;
int N, vis[MAXN], cnt;
vector <int> adj[MAXN];

void dfs(int u){
	if(vis[u]) return;
	vis[u]=1, cnt++;
	
	rep(i, 0, adj[u].size())
		dfs(adj[u][i]);
	
	return;	
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanint(N);
	
	int u, v, c;
	rep(i, 1, N){
		scanint(u), scanint(v), scanint(c);
		if(!c){
			if(u>v) swap(u, v);
			adj[u].pb(v);
		}
	}

	ll ans=ll(N)*(N-1)/2;
	
	rep(i, 1, N+1){
		if(!vis[i]){
			cnt=0;
			dfs(i);
			ans-=ll(cnt)*(cnt-1)/2;
		}
	}
	
	printf("%lld\n", ans);
	
	return 0;	
	
}
