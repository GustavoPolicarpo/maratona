// Author: Gustavo Policarpo
// Name: Earth Sled Tour
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2933

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
const int LOG=22;
int h[N], peso[N][LOG], pai[N][LOG], pset[N];

vector <ii> adj[N];
vector <iii> in;

void init(int n){
	in.clear();
	rep(i, 0, n){
		adj[i].clear(), 
		pset[i]=i;
		rep(j, 0, LOG) pai[i][j]=0, peso[i][j]=-INF;
	}
}

int findset(int x){
	if(pset[x]!=x) pset[x]=findset(pset[x]);
	return pset[x];
}
void unionset(int x, int y){
	x=findset(x), y=findset(y);
	if(x==y) return;
	pset[x]=y;
}
bool sameset(int x, int y){
	return findset(x)==findset(y);
}
void build_maximun_tree(){
	int x, y, c;
	rep(i, 0, in.size()){
		x=in[i].S.F, y=in[i].S.S, c=in[i].F;
		if(!sameset(x, y)){
			unionset(x, y);
			adj[x].pb(mp(y, c));
			adj[y].pb(mp(x, c));
		}
	}
}

void dfs(int u, int last){	
	rep(i, 0, adj[u].size()){
		int v=adj[u][i].F;
		if(v==last) continue;
		
		h[v]=h[u]+1;
		
		pai[v][0]=u;
		rep(j, 1, LOG) pai[v][j]=pai[pai[v][j-1]][j-1];
		
		peso[v][0]=adj[u][i].S;
		rep(j, 1, LOG) peso[v][j]=max(peso[v][j-1], peso[pai[v][j-1]][j-1]);
		
		dfs(v, u);
	}
	return;
}

int LCA(int a, int b){
	if(a==b) return 0;
	int ret=-INF;
	if(h[a]<h[b]) swap(a, b);
	for(int i=LOG-1; i>=0; i--){
		if(pai[a][i]<=0) continue;
		if(h[pai[a][i]]>=h[b]){
			ret=max(ret, peso[a][i]);
			a=pai[a][i];	
		}
	}
	//ret=min(ret, min(peso[a][0], peso[b][0]));
	if(a==b) return ret;
	for(int i=LOG-1; i>=0; i--){
		if(pai[a][i]!=pai[b][i]){
			ret=max(ret, max(peso[a][i], peso[b][i]));
			a=pai[a][i], b=pai[b][i];		
		}
	}
	ret=max(ret, max(peso[a][0], peso[b][0]));
	return ret;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, M, S, u, v, c;
	while(scanf("%d %d", &N, &M) !=EOF){
		init(N+2);
		rep(i, 0, M){
			scanint(u), scanint(v), scanint(c);
			u++, v++;
			in.pb(mp (c, mp(u, v)));
		}
		
		sort(in.begin(), in.end());
		build_maximun_tree();
		
		h[1]=0, peso[1][0]=INF, pai[1][0]=0;
		rep(i, 1, LOG) pai[1][i]=pai[pai[u][i-1]][i-1], peso[1][i]=INF;
		
		dfs(1, 1);
		
		scanf("%d", &S);
		while(S--){
			scanint(u), scanint(v);
			u++, v++;
			int out = LCA(u, v);
			printf("%d\n", out);
		}
	} 	
	
return 0;
}
