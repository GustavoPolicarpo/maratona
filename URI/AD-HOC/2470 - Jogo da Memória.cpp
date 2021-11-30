// Author: Gustavo Policarpo
// Name: Jogo da Memória
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2470

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

const int MAXN=50050;
const int MAXL=22;
int N, c1[MAXN], c2[MAXN];
vector <int> adj[MAXN];
int h[MAXN], pai[MAXN][MAXL];

void dfs(int u, int last){
	
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(v==last) continue;
		
		pai[v][0]=u;
		rep(j, 1, MAXL) pai[v][j]=pai[pai[v][j-1]][j-1];
		h[v]=h[u]+1;
		
		dfs(v, u);
	}
	
	return;
}

int LCA(int a, int b){
	if(h[a]<h[b]) swap(a, b);
	
	for(int i=MAXL-1; i>=0; i--){
		if(pai[a][i]==0) continue;
		if(h[pai[a][i]] >= h[b])
			a=pai[a][i];
	}
	
	if(a==b) return a;
	
	for(int i=MAXL-1; i>=0; i--){
		if(pai[a][i]!=pai[b][i])
			a=pai[a][i], b=pai[b][i];
	}
	
	return pai[a][0];
	
}

int main()
{
	int aux;
	scanint(N);
	rep(i, 1, N+1){
		scanint(aux);
		if(c1[aux]) c2[aux]=i;
		else c1[aux]=i;
	}
	
	int u, v;
	rep(i, 1, N){
		scanint(u), scanint(v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	
	h[1]=0;
	rep(i, 0, MAXL) pai[1][i]=0;
	dfs(1, 1);
	
	int ans=0;
	rep(i, 1, N/2 + 1){
		u=c1[i], v=c2[i];
		aux=LCA(u, v);
		ans+=h[u]+h[v]-2*h[aux];
	}
	
	printf("%d\n", ans);

	return 0;
	
}
