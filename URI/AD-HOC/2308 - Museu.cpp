// Author: Gustavo Policarpo
// Name: Museu
// Level: 10
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2308

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


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int tempo[1010], dist[1010];
vector <ii> adj[1010];

int dijsktra(int ini, int fim){
	
	memset(dist, INF, sizeof dist);
	priority_queue <ii> pq;
	
	rep(i, 0, adj[ini].size()){
		int v=adj[ini][i].F,
			cc=adj[ini][i].S;
		if(dist[v]<=cc+tempo[v]) continue;
		dist[v]=cc+tempo[v];
		pq.push(mp(-dist[v], v));
	}
	
	while(!pq.empty()){
		int u=pq.top().S, c=-pq.top().F; pq.pop();
		//cout << u  << " " << c << endl;
		if(u==fim) return c;
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F,
				cc=adj[u][i].S;
			if(dist[v]<=c+cc+tempo[v]) continue;
			dist[v]=c+cc+tempo[v];
			pq.push(mp(-dist[v], v));
		}
	}
	
	return INF;
}

int main(){
	
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, M;
	scanint(N), scanint(M);
	
	rep(i, 1, N+1) scanint(tempo[i]);
	
	int u, v, c;
	rep(i, 0, M){
		scanint(u), scanint(v), scanint(c);
		adj[u].pb(mp(v, c));
	}
	
	int ans=INF, atual;
	rep(i, 1, N+1)
		ans=min(ans, dijsktra(i, i));
	
	printf("%d\n", ans);
	
	return 0;
}

