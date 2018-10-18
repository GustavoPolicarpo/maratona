// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Caminhão
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1476

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

const int MAXV = 20020;
const int LMAXV = 22;

vector <ii> adj[MAXV];
vector <iii> edg;
int pai[MAXV][LMAXV], p[MAXV][LMAXV], h[MAXV], pset[MAXV];

void clear(int n){
	rep(i, 0, n+1){
		adj[i].clear();
		pset[i]=i;
	}	edg.clear();
}

void dfs(int u, int last){
	rep(i, 0, adj[u].size()){
		int v=adj[u][i].F;
		if(v==last) continue;
		
		h[v]=h[u]+1;
		
		pai[v][0]=u;
		rep(j, 1, LMAXV) pai[v][j] = pai[pai[v][j-1]][j-1];
		
		p[v][0]=adj[u][i].S;
		rep(j, 1, LMAXV) p[v][j] = min(p[v][j-1], p[pai[v][j-1]][j-1]);
		
		dfs(v, u);
	}
}


int findset(int x){
	if(x!=pset[x]) pset[x]=findset(pset[x]);
	return pset[x];
}
void unionset(int x, int y){
	x=findset(x), y=findset(y);
	pset[x]=y;
}
bool sameset(int x, int y){
	return findset(x) == findset(y);
}

void build_maximun_tree(){
	
	sort(edg.begin(), edg.end());
	reverse(edg.begin(), edg.end());
	
	rep(i, 0, edg.size()){
		int u=edg[i].S.F, 
			v=edg[i].S.S,
			c=edg[i].F;
		if(!sameset(u, v)){
			unionset(u, v);
			adj[u].pb(mp(v, c));
			adj[v].pb(mp(u, c));
		}
	}
	
}

int LCA(int a, int b){
	int ret=INF;
	
	if(h[a] < h[b]) swap(a, b);
	
	for(int i=LMAXV - 1; i>=0; i--){
		if(pai[a][i]<=0) continue;
		if(h[pai[a][i]] >= h[b]){
			ret=min(ret, p[a][i]);
			a=pai[a][i];
		}
	}
	
	if(a==b) return ret;
	
	for(int i=LMAXV - 1; i>=0; i--){
		if(pai[a][i]!=pai[b][i]){
			ret=min(ret, min(p[a][i], p[b][i]));
			a=pai[a][i], b=pai[b][i];
		}
	}
	
	ret=min(ret, min(p[a][0], p[b][0]));
	
	return ret;
	
}
int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	h[1]=0;
	rep(i, 0, LMAXV) pai[1][i]=0, p[1][i]=INF;
		
	int N, M, S;
	while(scanf("%d %d %d", &N, &M, &S)!=EOF){
		
		clear(N);
		
		int u, v, c;
		while(M--){
			scanf("%d %d %d", &u, &v, &c);
			edg.pb(mp(c, mp(u, v)));
		}
		
		build_maximun_tree();
		
		dfs(1, 1);
		
		while(S--){
			scanf("%d %d", &u, &v);
			printf("%d\n", LCA(u, v));
		}
		
	}
	
}
