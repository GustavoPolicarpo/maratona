// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Kill the Werewolf
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2354

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define INF 0x3f3f3f3f


int flow[110][110], grafo[110][110], source, sink, n, pai[110], grau[110];
vector <int> adj[110];

inline bool bfs(){
	queue <int> q;
	q.push(source);
	int vis[n+n+10];
	rep(i, 0, n+n+5) vis[i]=0, pai[i]=-1; vis[source]=1;
	while(!q.empty()){
		int u=q.front(); q.pop();
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			//cout << u << " " << v << " " << flow[u][v]<< '\n';
			if(flow[u][v]<=0 || vis[v]) continue;
			pai[v]=u, vis[v]=1;
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
}

int main(){
	scanf("%d", &n);
	int u, v, ans=0;
	rep(i, 1, n+1){
		scanf("%d %d", &u, &v);
		
		grafo[i][u+n]=1, grau[u]++;
		flow[i][u+n]=1, flow[u+n][i]=0;
		adj[i].pb(u+n), adj[u+n].pb(i);
		
		grafo[i][v+n]=1, grau[v]++;
		adj[i].pb(v+n), adj[v+n].pb(i);
		flow[i][v+n]=1, flow[v+n][i]=0;
	}
	source=0, sink=n+n+1;
	rep(i, 1, n+1) adj[source].pb(i), adj[i].pb(source), adj[i+n].pb(sink), adj[sink].pb(i+n);
	
	rep(i, 1, n+1){
		int capa=grau[i]-1, cnt=0;
		capa=max(capa, 0);
		
		memcpy(flow, grafo, sizeof flow);
		rep(j, 1, n+1){
			if(grafo[j][i+n] || j==i) flow[source][j]=0;
			else flow[source][j]=1, cnt++;
			
			if(grafo[i][j+n]) flow[j+n][sink]=max(capa-1, 0);
			else flow[j+n][sink]=capa;
		}
		int aux=maxFlow();
		
		//cout << aux << " " << grau[i] << "\n\n";
		if(aux<cnt) ans++;
	}
	
	printf("%d\n", ans);
	
	return 0;
}
