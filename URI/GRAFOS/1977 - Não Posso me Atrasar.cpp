// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Não Posso me Atrasar
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1977

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;

vector <ii> adj[101];
map<string, int> mapa; int cnt;
int X, N, V;
int dist[101];

int solve(int ini, int fim){
	memset(dist, 0x3f3f3f3f, sizeof dist);
	int cini = (X<=30 ? 30 : 50);
	priority_queue<ii> pq; pq.push(ii(-cini, ini));
	dist[ini] = cini;
	while(!pq.empty()){
		int u = pq.top().S, c = -pq.top().F; pq.pop();
		if(u==fim) return c;
		rep(i, 0, adj[u].size()){
			int v = adj[u][i].F,
				cc = adj[u][i].S;
			if(dist[v]>c+cc){
				dist[v] = c+cc;
				pq.push(ii(-dist[v], v));
			}
		}
	}
}

int main(){
	
	while(scanf("%d %d %d", &X, &N, &V) and X+N+V){
		rep(i, 0, V+10) adj[i].clear(); cnt = 0;
		mapa.clear();
		string a, b; int c;
		rep(i, 0, N){
			cin >> a >> b >> c;
			if(!mapa.count(a)) mapa[a] = cnt++;
			if(!mapa.count(b)) mapa[b] = cnt++;
			rep(j, 0, adj[mapa[a]].size()){
				if(adj[mapa[a]][j].F==mapa[b]){
					adj[mapa[a]][j].S = c;
				}
			}
			adj[mapa[a]].pb(ii(mapa[b], c));
		}
		int ans = solve(mapa["vazea"], mapa["alto"]);
		int h = (17+ans/60)%24, m = ans%60;
		printf("%02d:%02d\n", h, m);
		if(ans>60) puts("Ira se atrasar");
		else puts("Nao ira se atrasar");
	}
	
	
	return 0;
}  
