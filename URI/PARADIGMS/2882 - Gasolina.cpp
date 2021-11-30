// Author: Gustavo Policarpo
// Name: Gasolina
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2882

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int INF = 0x3f3f3f3f;

struct use{
	int u, v, c, f, t;
	//from, to, capacity, flow
};

int P, R, C;
vector <iii> routes;
int D[1010], E[1010];
vector <int> adj[2020];
vector <use> edg;


void add_edge(int u, int v, int c, int f, int t){
	adj[u].pb(edg.size()); edg.pb(use{u, v, c, f, t});
	adj[v].pb(edg.size()); edg.pb(use{v, u, 0, 0, t});
}

int dist[2020], ptr[2020];
int source, sink;
bool bfs(int cut){
	memset(dist, -1, sizeof dist); dist[source] = 0;
	queue <int> q; q.push(source);
	while(!q.empty()){
		int u = q.front(); q.pop();
		if(u==sink) return true;
		rep(i, 0, adj[u].size()){
			int id = adj[u][i];
			use aux = edg[id];
			if(dist[aux.v]!=-1 || aux.t>cut) continue;
			if(aux.c - aux.f > 0){
				dist[aux.v] = dist[u]+1;
				q.push(aux.v);
				
			}
		}
	}
	return false;
}

int dfs(int u, int c, int cut){
	if(u==sink) return c;
	int ret = 0;
	for(; ptr[u]<adj[u].size(); ptr[u]++){
		int id = adj[u][ptr[u]];
		use aux = edg[id];
		if(dist[aux.v]!=dist[u]+1 || aux.t > cut) continue;
		if(aux.c - aux.f > 0){
			ret = dfs(aux.v, min(c, aux.c-aux.f), cut);
			if(ret>0){
				edg[id].f+=ret;
				edg[id^1].f-=ret;
				break;
			}
		}
	}
	return ret;
}

int maxF(int cut){
	int ret = 0;
	while(bfs(cut)){
		memset(ptr, 0, sizeof ptr);
		while(42){
			int push = dfs(source, 1e4, cut);
			if(!push) break;
			ret+=push;
		}
	}
	return ret;
}

int main(){
	
	
	int need = 0;
	scanf("%d %d %d", &P, &R, &C);
	source = 0, sink = P+R+2;
	rep(i, 1, P+1) scanf("%d", &D[i]), add_edge(i+R, sink, D[i], 0, 0), need+=D[i];
	rep(i, 1, R+1) scanf("%d", &E[i]), add_edge(source, i, E[i], 0, 0);
	int u, v, c;
	rep(i, 0, C){
		scanf("%d %d %d", &u, &v, &c);
		add_edge(v, u+R, 1e4, 0, c);
	}
	
	int ini = 1, fim = 1e6+1, mid, ans = -1;
	while(ini<=fim){
		mid = (ini+fim)/2;
		int aux = maxF(mid);
		if(aux==need){
			ans = mid;
			fim = mid-1;
		}else{
			ini = mid+1;
		}
		rep(i, 0, edg.size()) edg[i].f = 0;
	}
	
	printf("%d\n", ans);
	
	
	
	return 0;
}  
