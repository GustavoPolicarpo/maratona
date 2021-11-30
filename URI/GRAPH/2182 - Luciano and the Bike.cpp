// Author: Gustavo Policarpo
// Name: Luciano and the Bike
// Level: 10
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2182

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
#define error 1e-4

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

int N, M, vis[100001], aux;
vector <ii> adj[100001]; set<ii> edg;

ii dfs(int u){
	if(vis[u]) return mp(0, 0);
	vis[u]=1;
	ii ret=mp(0, 0);
	rep(i, 0, adj[u].size()){
		int v=adj[u][i].F; if(v>aux) aux=v;
		if(!edg.count(mp(u, v))){
			ret.F++, ret.S+=adj[u][i].S;
			edg.insert(mp(u, v)); edg.insert(mp(v, u));
		}
		if(vis[v]) continue;
		ii rr=dfs(v);
		ret.F+=rr.F, ret.S+=rr.S;
	}
	return ret;
}
int main()
{
	scanf("%d %d", &N, &M);
	int u, v, w;
	rep(i, 0, M){
		//scanf("%d %d %d", &u, &v, &w);
		scanint(u), scanint(v), scanint(w);
		adj[u].pb(mp(v, w));
		adj[v].pb(mp(u, w));
	}
	int out=-1; double best=INF;
	for(int i=N; i>0; i--){
		if(adj[i].size()==0){
			printf("%d\n", i);
			return 0;
		}
		if(!vis[i]){
			aux=i;
			ii comp=dfs(i);
			//cout << i << " " << comp.F << "  " << comp.S << " " << aux << endl;
			if(comp.S==0){
				printf("%d\n", aux);
				return 0;
			}
			double possible=double(comp.S)/comp.F;
			//cout << possible << endl;
			if(possible<best-error){
				out=aux, best=possible;
			}
		}
	}
	printf("%d\n", out);


return 0;

}
