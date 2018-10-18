// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Caminho Seguro
// Nível: 8
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1617

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

const int MAX = 110;
const int INF = 0x3f3f3f3f;

int edg[MAX][MAX], source, sink, N, M, pai[MAX], dist[MAX];

int dijsktra(){
	
	rep(i, 1, N+1) dist[i]=INF; dist[source]=0;
	priority_queue <ii> pq; pq.push(mp(0, source));
	
	while(!pq.empty()){
		int u=pq.top().S, c=-pq.top().F; pq.pop();
		
		if(u==sink) return c;
		
		rep(v, 1, N+1){
			if(edg[u][v] == INF) continue;
			if(dist[v] > dist[u] + edg[u][v]){
				dist[v] = dist[u] + edg[u][v];
				pai[v]=u;
				pq.push(mp(-dist[v], v));
			}
		}
	}
	
	return INF;
	
}


void rec_path(){
	
	int u=sink;
	while(u!=source){
		edg[pai[u]][u]=INF;
		edg[u][pai[u]] = -edg[u][pai[u]];
		u=pai[u];
	}
	
	return;
	
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d", &N) and N){
		
		scanf("%d", &M);
		rep(i, 1, N+1){
			rep(j, 1, N+1){
				edg[i][j]=INF;
			}
			pai[i]=0;
		}
		
		source=1, sink=N;
		
		int u, v, c;
		while(M--){
			scanf("%d %d %d", &u, &v, &c);
			edg[u][v]=c;
			edg[v][u]=c;
		}
		
		int ans=INF;
		while(1){
			int aux=dijsktra(); rec_path();
			
			//cout << aux << "\n"; system("pause");
			aux+=dijsktra(); rec_path();
			
			if(aux>=ans) break;
			ans=aux;
		}
		
		if(ans>=INF) puts("Pernoite.");
		else printf("%d\n", ans);
		
	}
	
	return 0;
	
}
