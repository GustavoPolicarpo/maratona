// Author: Gustavo Policarpo
// Name: Even Obsession
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1931

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


int vis[100001][2], dist[100001][2], C, V;
vector <ii> adj[100001];

int dijsktra(){
	memset(dist, INF, sizeof dist);
	priority_queue <iii> pq;
	pq.push(mp(0, mp(0, 1))); dist[1][0]=0;
	
	while(!pq.empty()){
		int u=pq.top().S.S, c=pq.top().S.F, d=-pq.top().F; pq.pop();
		//cout << u << " " << c << endl;
		if(u==C && c==0){
			return d;
		}
		if(dist[u][c]!=d) continue;
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F;
			int e=adj[u][i].S;
			if(dist[v][1-c]>dist[u][c]+e){
				dist[v][1-c]=dist[u][c]+e;
				pq.push(mp(-dist[v][1-c], mp(1-c, v)));
			}	
		}	
	}
	return -1;	
}
int main(){
	scanint(C), scanint(V);
	int u, v, c;
	rep(i, 0, V){
		scanint(u), scanint(v), scanint(c);
		adj[u].pb(mp(v, c));
		adj[v].pb(mp(u, c));
	}
	int out=dijsktra();
	printf("%d\n", out);
	
				
return 0;
}


