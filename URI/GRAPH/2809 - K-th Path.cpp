// Author: Gustavo Policarpo
// Name: K-th Path
// Level: 10
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2809

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

int n, m, q, ini, fim;
vector <ii> adj[10010];
set <ii> st;
int dist[10010][111];

void dijsktra(){
	memset(dist, 0x3f3f3f3f, sizeof dist);
	priority_queue <iii> pq;
	pq.push(iii(ii(0, 0), ini)); dist[ini][0] = 0;
	while(!pq.empty()){
		int u = pq.top().S, c = -pq.top().F.F, q = pq.top().F.S; pq.pop();
		rep(i, 0, adj[u].size()){
			int v = adj[u][i].F,
				cc = adj[u][i].S;	
			int go = v, goc = cc+c, goq = q+(!st.count(ii(u, v)));
			goq = min(goq, 101);
			if(dist[go][goq]<=goc) continue;
			dist[go][goq] = goc;
			pq.push(iii(ii(-goc, goq), go));
		}
	}
}

int main(){
	
	scanf("%d %d %d", &n, &m, &q);
	scanf("%d %d", &ini, &fim);
	
	string s; getline(cin, s); getline(cin, s);
	stringstream ss; ss << s;
	
	int u, v, c, last = ini;
	while(ss >> u){
		if(u==last) u = last;
		else{
			st.insert(ii(last, u));
			last = u;
		}
	}
	
	rep(i, 0, m){
		scanf("%d %d %d", &u, &v, &c);
		adj[u].pb(ii(v, c));
	}
	
	dijsktra();
	
	for(int i=100; i>=0; i--){
		dist[fim][i] = min(dist[fim][i], dist[fim][i+1]);
	}
	
	while(q--){
		scanf("%d %d", &u, &v);
		if(dist[fim][u]<=dist[fim][0]+v) puts("SIM");
		else puts("NAO");
	}

	return 0;
}
