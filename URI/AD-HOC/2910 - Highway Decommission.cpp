// Author: Gustavo Policarpo
// Name: Highway Decommission
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2910

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<ll,int> ii;

struct use{
	int v, l, c;
};

vector <use> adj[10010];
ii dist[10010];
int N, M;

void dijsktra(){
	rep(i, 0, N+2) dist[i] = ii(1e18, 1e9);
	priority_queue <ii> pq;
	pq.push(ii(0, 1)); dist[1] = ii(0, 0);
	
	while(!pq.empty()){
		int u = pq.top().S; ll d = -pq.top().F; pq.pop();
		rep(i, 0, adj[u].size()){
			int v = adj[u][i].v,
				l = adj[u][i].l,
				c = adj[u][i].c;
			if(dist[v].F > d+l){
				dist[v] = ii(d+l, c);
				pq.push(ii(-dist[v].F, v));
			}
			else if(dist[v].F==d+l){
				dist[v].S = min(dist[v].S, c);
			}
		}
	}
}

int main(){
	
	scanf("%d %d", &N, &M); int u, v, l, c;
	rep(i, 0, M){
		scanf("%d %d %d %d", &u, &v, &l, &c);
		adj[u].pb(use{v, l, c});
		adj[v].pb(use{u, l, c});
	}
	
	dijsktra();
	
	ll ans = 0;
	rep(i, 1, N+1) ans+=dist[i].S;
	cout << ans << '\n';
	
	
	return 0;
}

