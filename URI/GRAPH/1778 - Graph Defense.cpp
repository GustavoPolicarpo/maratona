// Author: Gustavo Policarpo
// Name: Graph Defense
// Level: 10
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1778

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;


int N, M, F, P, Q;
vector <int> adj[1010];
vector <int> monster[1010];
int damage[1010];
int simul[1010];
int vis[1010];

void bfs(int ini, int atack, int alc){
	
	rep(i, 0, N+2) vis[i]=0;
	queue <ii> q;  vis[F]=1;
	q.push(mp(ini, 0)); vis[ini]=1;
	
	while(!q.empty()){
		
		int u=q.front().F, t=q.front().S; q.pop();
		
		damage[u]+=atack;
		
		if(t==alc) continue;
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(vis[v]) continue;
			q.push(mp(v, t+1)); vis[v]=1;
		}
		
	}
}

int solve(){
	
	priority_queue <ii> pq; int ret=0;
	pq.push(mp(0, F)); simul[F]=0;
	
	while(!pq.empty()){
		
		int u=pq.top().S, t=-pq.top().F; pq.pop();
		
		rep(i, 0, monster[u].size()) if(monster[u][i]>t) ret++;
		monster[u].clear();
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(simul[v]<=t+damage[v]) continue;
			simul[v]=t+damage[v];
			pq.push(mp(-simul[v], v));
		}
	}
	
	return ret;
	
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	
	int T, z=1; cin >> T;
	
	while(T--){
		
		scanf("%d %d %d", &N, &M, &F);
		
		rep(i, 0, N+2){
			adj[i].clear();
			monster[i].clear();
			damage[i]=0;
			simul[i]=INF;
		}
		
		int u, v, c;
		while(M--){
			scanf("%d %d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		scanf("%d", &P);
		rep(i, 0, P){
			scanf("%d %d %d", &u, &v, &c);
			bfs(u, v, c);
		}
		
		scanf("%d", &Q);
		while(Q--){
			scanf("%d %d", &u, &v);
			monster[u].pb(v);
		}
		
		printf("Caso #%d: %d\n", z++, solve());
		
	}
		
	return 0;
	
}
