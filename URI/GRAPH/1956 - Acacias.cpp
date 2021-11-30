// Author: Gustavo Policarpo
// Name: Acacias
// Level: 8
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1956

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
#define MAXN 100001
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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, pset[10001], vis[10001];
vector <iii> edg;
vector <int> adj[10001];

int findset(int x){
	if(x!=pset[x]){
		pset[x]=findset(pset[x]);
	}
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
	scanf("%d", &N);
	int k, u, v, c;
	rep(i, 1, N){
		scanf("%d", &k); pset[i]=i;
		rep(j, 0, k){
			scanf("%d %d", &v, &c);
			edg.pb(mp(c, mp(i, v)));
			adj[i].pb(v), adj[v].pb(i);
		}
	} pset[N]=N;
	sort(edg.begin(), edg.end());
	
	ll mst=0;
	rep(i, 0, edg.size()){
		    u=edg[i].S.F,
			v=edg[i].S.S,
			c=edg[i].F;
		if(!sameset(u, v)){
			unionset(u, v);
			mst+=c;
		}
	}
	
	int cnt=0;
	rep(i, 1, N+1){
		if(!vis[i]){
			cnt++, dfs(i);
		}
	}
	
	printf("%d %lld\n", cnt, mst);
	
	return 0;
}


