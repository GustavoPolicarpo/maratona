// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Max, o Louco
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1529

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

const int MAXV=12, MAXN=52;

vector <ii> adj[MAXV];
int N, M, capa, custo[MAXV], dist[MAXV][MAXN];

int dijkstra(){
	
	priority_queue <iii> pq;
	pq.push(mp(0, mp(capa, 1))); dist[1][capa]=0;
	
	while(!pq.empty()){
		int u=pq.top().S.S, ct=-pq.top().F, ca=pq.top().S.F; pq.pop();
		
		if(u==N) return ct;
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F, cc=adj[u][i].S;
			
			rep(j, 0, capa-ca+1){
				if(ca+j < cc) continue;
				
				int aux=ca+j-cc;
				if(dist[v][aux] <= ct + j*custo[u]) continue;
				
				dist[v][aux] = ct + j*custo[u];
				pq.push(mp(-dist[v][aux], mp(aux, v)));
			}
		}
		
	}
	
	return -1;
	
}


int main()
{
	
	while(scanf("%d %d %d", &N, &M, &capa) and N+M+capa){
		
		rep(i, 1, N+1) adj[i].clear();
		
		int u, v, c;
		rep(i, 0, M){
			scanf("%d %d %d", &u, &v, &c);
			adj[u].pb(mp(v, c));
			adj[v].pb(mp(u, c));
		}
		
		rep(i, 1, N+1){
			scanf("%d", &custo[i]);
			rep(j, 0, capa+1) dist[i][j]=INF;
		}
		
		printf("%d\n", dijkstra());
		
	}
	
	
	return 0;
	
}
