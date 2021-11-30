// Author: Gustavo Policarpo
// Name: Choosing the Pairs
// Level: 10
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1562

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned long long int ull;
typedef pair < int, ll > ii;
typedef pair < double, int > iii;


vector <int> adj[10010], adj2[10010]; 
int vis[10010], par[10010], grau[10010], cnt;

struct use{
	int grau, ver;
	
	bool operator() (use a, use b){
		
		if(a.grau==0 && b.grau==0){
			if(a.ver < b.ver) return false;
			if(a.ver > b.ver) return true;
		}
		
		if(a.grau == 0) return false;
		if(b.grau == 0) return true;
		
		if(a.ver < b.ver) return false;
		if(a.ver > b.ver) return true;
	}
};


void dfs(int u){
	
	if(vis[u]) return;
	vis[u]=1, cnt++;
	
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(!vis[v])
			dfs(v);
	}
	rep(i, 0, adj2[u].size()){
		int v=adj2[u][i];
		if(!vis[v])
			dfs(v);
	}
	
	return;
	
}

void solve(int N){
	
	priority_queue <use, vector <use>, use> pq; cnt=0;
	use aux;
		
	/*rep(i, 1, N+1){
		
		if(grau[i] < 0) continue;
		
		int v = adj[i][0];
		
		if(grau[i]==0){
			grau[i]=grau[v]=-1;
			par[i]=v, 
			par[v]=i,
			cnt+=2;
			grau[adj[v][0]]--;
			continue;
		}
		
		if(adj[v].size()==1 && adj[v][0]==i){
			grau[i]=grau[v]=-1;
			par[i]=v, 
			par[v]=i,
			cnt+=2;
			continue;
		}
		
	}*/
	
	rep(i, 1, N+1){
		//if(grau[i] < 0) continue;
		aux.grau=grau[i], 
		aux.ver=i;
		pq.push(aux);
	}
	
	set <int> used;
	while(!pq.empty()){
		//cout << pq.top().ver << " " << pq.top().grau  << '\n';
		int u=pq.top().ver; pq.pop();
		//cout << cnt << " " << N <<'\n';
		int v = adj[u][0];
		
		if(par[u] || par[v]) continue;
		if(used.count(u) || used.count(v)) continue;
		used.insert(u), used.insert(v);
		
		grau[u]=grau[v]=-1;
		par[u]=v, 
		par[v]=u;
		cnt+=2;
		grau[adj[v][0]]--;
		
		aux.grau=grau[adj[v][0]],
		aux.ver=adj[v][0];
		if(!par[aux.ver])
			pq.push(aux);
		
	}
		
	return;
	
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N, aux, yep; 
	
	while(scanf("%d", &N) !=EOF){
		
		rep(i, 1, N+1){
			adj[i].clear(), 
			adj2[i].clear(), 
			vis[i]=par[i]=grau[i]=0;
		}	cnt=0;
		
		rep(i, 1, N+1){
			scanf("%d", &aux);
			adj[i].pb(aux);
			adj2[aux].pb(i);
			grau[aux]++;
		}
		
		if(N&1){
			puts("IMPOSSIBLE");
			continue;
		}
		
		yep=1;
		rep(i, 1, N+1){
			if(vis[i]) continue;
			cnt=0;
			dfs(i);
			if(cnt&1){
				yep=0;
				break;
			}
		}
		
		if(!yep){
			puts("IMPOSSIBLE");
			continue;
		}
		
		solve(N);
		
		set <int> used;
		yep=1;
		rep(i, 1, N+1){
			if(used.count(par[i])){
				yep=false;
				break;
			}
			used.insert(par[i]);
			if(!par[i]){
				yep=false;
				break;
			}
		}
		
		
		if(!yep){
			puts("IMPOSSIBLE");
			continue;
		}
		
		rep(i, 1, N+1){
			if(i-1) printf(" ");
			printf("%d", par[i]);
		}	printf("\n");
		
	}

	return 0;
	
}
