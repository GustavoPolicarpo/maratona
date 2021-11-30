// Author: Gustavo Policarpo
// Name: Reversing Arrows
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2576

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

#define INF 0x3f3f3f3f
const int mod=1e9+7;


vector <ii> adj[10010];
int dist[10010];

int dijsktra(int ini, int fim){

	memset(dist, INF, sizeof dist);
	priority_queue <ii> pq; pq.push(mp(0, ini)); dist[ini]=0;
	
	while(!pq.empty()){
		
		int u=pq.top().S, c=-pq.top().F; pq.pop();
		
		if(u==fim) return c;
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F,
				cc=adj[u][i].S;
			if(dist[v]<=c+cc) continue;
			dist[v]=c+cc;
			pq.push(mp(-dist[v], v));		
		}
	
	}
	

	return INF;
}


int main(){

	int C, S, A, B; cin >> C >> S >> A >> B;
	int u, v;
	
	while(S--){
		scanf("%d %d", &u, &v);
		adj[u].pb(mp(v, 0));
		adj[v].pb(mp(u, 1));
	}
	
	int AB=dijsktra(A, B);
	int BA=dijsktra(B, A);
	
	if(AB<BA) printf("Bibi: %d\n", AB);
	else if(BA<AB) printf("Bibika: %d\n", BA);
	else puts("Bibibibika"); 
    
    return 0;
     
}
