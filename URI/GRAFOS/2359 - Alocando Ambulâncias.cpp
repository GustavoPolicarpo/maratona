// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Alocando Ambulâncias
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2359

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

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

void scanint(int &x)
{
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}


int N, M, Q, dist[1010];
vector <ii> adj[1010];

void solve(int ini){
	
	queue <ii> pq;
	pq.push(mp(0, ini));
	
	while(!pq.empty()){
		int u=pq.front().S, c=pq.front().F; pq.pop();
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F,
				cc=adj[u][i].S;
			if(dist[v] <= c+cc) continue;
			dist[v]=c+cc;
			pq.push(mp((c+cc), v));
		}
		
	}
	
	return;
	
}
int main()
{
	int u, v, c, ans, last=1;
	
	while(scanf("%d %d %d", &N, &M, &Q)!=EOF){
		
		rep(i, last, N+1) dist[i]=INF;
		
		rep(i, 0, M){
			scanint(u),scanint(v),scanint(c);
			adj[u].pb(mp(v, c));
			adj[v].pb(mp(u, c));
		}
		
		while(Q--){
			scanint(u);
			dist[u]=0;
		}
		
		
		rep(i, 1, N+1){
			if(dist[i]==0){
				solve(i);
			}
		}
		
		ans=0;
		rep(i, 1, N+1){
			ans=max(ans, dist[i]);
			dist[i]=INF;
			adj[i].clear();
		}	last=N;
		
		printf("%d\n", ans);
		
	}
	
	return 0;
	
}
