// Author: Gustavo Policarpo
// Name: Tarzan
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2412

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


int n, d, vis[1010];
vector <int> adj[1010];


int dist(ii a, ii b){
	return (a.F - b.F)*(a.F - b.F) + (a.S - b.S)*(a.S - b.S);
}
void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;
	rep(i, 0, adj[u].size())
		dfs(adj[u][i]);
	return;
}
int main()
{
	scanf("%d %d", &n, &d);
	ii in[n];
	rep(i, 0, n) scanf("%d %d", &in[i].F, &in[i].S);
	
	rep(i, 0, n){
		rep(j, i+1, n){
			if(dist(in[i], in[j]) <= d*d){
				adj[i].pb(j),
				adj[j].pb(i);
			}
		}
	}
	
	dfs(0);
	
	bool yep=1;
	rep(i, 0, n){
		if(!vis[i]){
			yep=false;
			break;
		}
	}
	
	yep ? puts("S") : puts("N");
	
	return 0;
	
}
