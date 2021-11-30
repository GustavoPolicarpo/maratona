// Author: Gustavo Policarpo
// Name: Hooligan
// Level: 8
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1394

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;
typedef pair <int, int> ii;
typedef long long int ll;

struct use{
	int from, to, cap, flow;
	use() {};
	use(int _from, int _to, int _cap, int _flow){
		from = _from;
		to = _to;
		cap = _cap;
		flow = _flow;
	}
};

#define MAX 1001
int source, sink, cnt;
vector <int> adj[MAX];
vector <use> edg;

void add_edge(int u, int v, int c, int f){
	adj[u].pb(edg.size());
	edg.pb(use(u, v, c, 0));
	adj[v].pb(edg.size());
	edg.pb(use(v, u, 0, 0));
}

int dst[MAX];
bool bfs(){
	rep(i, 0, cnt+2) dst[i] = -1;
	queue <ii> q; q.push(ii(source, 0));
	dst[source] = 0;
	while(!q.empty()){
		int u = q.front().F, d = q.front().S; q.pop();
		if(u==sink) return true;
		rep(i, 0, adj[u].size()){
			int id = adj[u][i];
			use aux = edg[id];
			if(dst[aux.to]!=-1) continue;
			if(aux.cap-aux.flow>0){
				dst[aux.to] = d+1;
				q.push(ii(aux.to, d+1));
			}
		}
	}
	return false;
}

int ptr[MAX];
int dfs(int u, int c){
	if(u==sink) return c;
	ll ret = 0;
	for(; ptr[u]<adj[u].size(); ptr[u]++){
		int id = adj[u][ptr[u]];
		use aux = edg[id];
		if(dst[aux.to]!=dst[u]+1) continue;
		if(aux.cap-aux.flow>0){
			ret = dfs(aux.to, min(c, aux.cap-aux.flow));
			if(ret>0){
				edg[id].flow+=ret;
				edg[id^1].flow-=ret;
				return ret;
			}
		}
	}
	return ret;
}

int maxFlow(){
	int ret = 0;
	while(bfs()){
		rep(i, 0, cnt+2) ptr[i] = 0;
		while(1){
			int push = dfs(source, 1<<30);
			if(!push) break;
			ret+=push;
		}
	}
	return ret;
}

int N, M, G;
int foi[44][44], total[44];
map<ii, int> mapa;

int main(){
	
	while(scanf("%d %d %d", &N, &M, &G) and N){
		
		memset(total, 0, sizeof total); mapa.clear();
		rep(i, 0, N+2) rep(j, 0, N+2) foi[i][j] = 0;
		rep(i, 0, cnt+2) adj[i].clear(); edg.clear(); cnt = 1;
		
		int u, v; char op;
		rep(i, 0, G){
			scanf("%d %c %d", &u, &op, &v);
			if(op=='>') total[u]+=2;
			else if(op=='=') total[u]++, total[v]++;
			else total[v]+=2;
			foi[u][v]++, foi[v][u]++;
		}
		
		rep(i, 1, N) rep(j, i+1, N)
			mapa[ii(i, j)] = cnt++;
		rep(i, 1, N) mapa[ii(i, i)] = cnt++;
		
		source = 0, sink = cnt; int sum = 0;
		rep(i, 1, N) total[0]+=(M-foi[0][i])*2;
		
		int deuRuim = 0;
		rep(i, 1, N){
			rep(j, i+1, N){
				add_edge(source, mapa[ii(i, j)], (M-foi[i][j])*2, 0);
				add_edge(mapa[ii(i, j)], mapa[ii(i, i)], 0x3f3f3f3f, 0);
				add_edge(mapa[ii(i, j)], mapa[ii(j, j)], 0x3f3f3f3f, 0);
				sum+=(M-foi[i][j])*2;
			}
			add_edge(mapa[ii(i, i)], sink, total[0]-total[i]-1, 0);
			deuRuim |= ( total[0]-total[i]-1 < 0 );
		}
		
		int maxF = maxFlow();
		if(!deuRuim && maxF==sum) puts("Y");
		else puts("N");
		
	}
	
	return 0;
}
