// Author: Gustavo Policarpo
// Name: Imperial Roads
// Level: 10
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2703

#include<bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x);

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int N, R, Q, pset[100010];
int u, v, c, mst = 0;
int h[100010], pai[100010][22], are[100010][22];

void scanint(int &x){
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

vector <iii> edg;
vector <ii> adj[100010];

map<ii, int> mapa;

int findset(int x){
	if(x!=pset[x]) pset[x] = findset(pset[x]);
	return pset[x];
}

void unionset(int x, int y){
	x = findset(x), y = findset(y);
	pset[x] = y;
}

bool sameset(int x, int y){
	return findset(x)==findset(y);
}

void dfs(int u, int last){
	rep(i, 0, adj[u].size()){
		int v = adj[u][i].F,
			c = adj[u][i].S;
		if(v==last) continue;
		h[v] = h[u]+1, pai[v][0] = u, are[v][0] = c;
		rep(j, 1, 22){
			pai[v][j] = pai[pai[v][j-1]][j-1],
			are[v][j] = max(are[v][j-1], are[pai[v][j-1]][j-1]);
		}
		dfs(v, u);
	}
}

int max_are(int a, int b){
	if(h[a] < h[b]) swap(a, b); int ret = 0;
	for(int i=21; i>=0; i--){
		if(h[pai[a][i]]>=h[b]){
			ret = max(ret, are[a][i]),
			a = pai[a][i];
		}
	}
	if(a==b) return ret;
	for(int i=21; i>=0; i--){
		if(pai[a][i]!=pai[b][i]){
			ret = max(ret, max(are[a][i], are[b][i])),
			a = pai[a][i], b = pai[b][i];
		}
	}
	ret = max(ret, max(are[a][0], are[b][0]));
	return ret;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	scanf("%d %d", &N, &R);
	
	rep(i, 1, N+1) pset[i] = i;
	
	rep(i, 0, R){
		scanint(u), scanint(v), scanint(c);
		edg.pb(iii(c, ii(u, v)));
		mapa[ii(min(u, v), max(u, v))] = c;
	}
	
	sort(edg.begin(), edg.end());
	
	rep(i, 0, edg.size()){
		u = edg[i].S.F,
		v = edg[i].S.S,
		c = edg[i].F;
		if(!sameset(u, v)){
			unionset(u, v);
			mst+=c;
			adj[u].pb(ii(v, c));
			adj[v].pb(ii(u, c));
		}
	}
	
	h[1] = 1; dfs(1, 1);
	
	scanf("%d", &Q);
	while(Q--){
		scanint(u), scanint(v);
		printf("%d\n", mst + mapa[ii(min(u, v), max(u, v))] - max_are(u, v));
	}
	
	return 0;
}
