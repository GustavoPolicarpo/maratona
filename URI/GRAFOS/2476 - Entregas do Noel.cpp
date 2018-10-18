// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Entregas do Noel
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2476

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

const int N=100010;
int h[N], pai[N], nn[N];
map<string, int> mapa;
vector <int> adj[N];

void dfs(int u, int last){
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(v==last) continue;
		pai[v]=u;
		h[v]=h[u]+1;
		dfs(v, u);
	}
}
int LCA(int a, int b){
	
	set <int> ret;
	if(h[a]<h[b]) swap(a, b);
	
	while(h[a]>h[b]){
		ret.insert(nn[a]);
		a=pai[a];
	}
	
	while(a!=b){
		ret.insert(nn[a]);
		a=pai[a];
		ret.insert(nn[b]);
		b=pai[b];
	}
	
	ret.insert(nn[a]);
	
	return ret.size();
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m, cnt=0;
	char name[22];
	
	scanint(n), scanint(m);
	rep(i, 1, n+1){
		scanf("%s", name);
		if(!mapa.count(name)) mapa[name]=cnt++;
		nn[i]=mapa[name];
	}
	
	int u, v;
	rep(i, 1, n){
		scanint(u), scanint(v);
		adj[u].pb(v);
		adj[v].pb(u); 	
	}
	
	h[1]=0;
	pai[1]=0;
	dfs(1, 1);
		
	while(m--){
		scanint(u), scanint(v);
		printf("%d\n", LCA(u, v));
	}
	
	return 0;
	
}
