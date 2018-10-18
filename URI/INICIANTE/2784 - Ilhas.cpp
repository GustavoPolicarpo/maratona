// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ilhas
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2784

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int dist[1010];
vector <ii> adj[1010];
int N, M, ini;

void dijsktra(){
	priority_queue <ii> pq; pq.push(ii(0, ini));
	memset(dist, 0x3f3f3f3f, sizeof dist);
	while(!pq.empty()){
		int u = pq.top().S, c = -pq.top().F; pq.pop();
		rep(i, 0, adj[u].size()){
			int v = adj[u][i].F,
				cc = adj[u][i].S;
			if(dist[v]<=c+cc) continue;
			dist[v] = c + cc;
			pq.push(ii(-dist[v], v));
		}
	}
}

int main(){
	
	
	scanf("%d %d", &N, &M);
	int u, v, c;
	rep(i, 0, M){
		scanf("%d %d %d", &u, &v, &c);
		adj[u].pb(ii(v, c));
		adj[v].pb(ii(u, c));
	}
	scanf("%d", &ini);
	dijsktra();
	
	int menor = 0x3f3f3f3f, maior = 0;
	rep(i, 1, N+1) menor = min(menor, dist[i]), maior = max(maior, dist[i]);
	cout << maior - menor << '\n';

	return 0;
}
