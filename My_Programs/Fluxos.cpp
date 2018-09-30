const int N=210;
int flow[N][N], source, sink, n, pai[N];
vector <int> adj[N];

void init(){
	rep(i, 0, n*2+2){
		adj[i].clear();
		rep(j, 0, n*2+2) flow[i][j]=0;
	}
}
inline bool bfs(){
	queue <int> q;
	q.push(source);
	int vis[N];
	rep(i, 0, n*2+2) vis[i]=0, pai[i]=-1;
	while(!q.empty()){
		int u=q.front(); q.pop();	
		vis[u]=1;
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(flow[u][v]<=0 || vis[v]) continue;	
			pai[v]=u;		
			q.push(v);
		}
	}
	return vis[sink];
}
int maxFlow(){
	int maxF=0;
	while(bfs()){
		int u=sink, minF=INF;
		while(pai[u]!=-1){
			minF=min(minF, flow[pai[u]][u]);
			u=pai[u];
		}
		maxF+=minF;
		u=sink;
		while(pai[u]!=-1){
			flow[u][pai[u]]+=minF;
			flow[pai[u]][u]-=minF;
			u=pai[u];
		}
	}
	return maxF;
}	//fluxomax=maxFlow()

/**************************/
int edg[MAX][MAX], source, sink, N, M, pai[MAX], dist[MAX];
int bellman(){
	rep(i, 1, N+1) dist[i]=INF; dist[source]=0;
	
	rep(i, 1, N)
	rep(u, 1, N+1)
	rep(v, 1, N+1){
		if(edg[u][v]==INF) continue;
		if(dist[v] > dist[u] + edg[u][v]){
			dist[v] = dist[u] + edg[u][v];
			pai[v]=u;
		}
	}
	return dist[sink];
}
void rec_path(){
	int u=sink;
	while(u!=source){
		edg[pai[u]][u]=INF;
		edg[u][pai[u]] = -edg[u][pai[u]];
		u=pai[u];
	}
	return;
	
}	//fluxo=bellman(), rec_path()
