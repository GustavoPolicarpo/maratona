// Author: Gustavo Policarpo
// Name: Trip Programming
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2731

#pragma comment(linker, "/stack:200000000")                                     
#pragma GCC optimize("Ofast")                                                   
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")   
#define _CRT_SECURE_NO_WARNINGS          
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

typedef long long int ll;
typedef pair <int, int> ii;


int C, E;
vector <ii> adj[18];

int main(){
	
	while(scanf("%d %d", &C, &E) and (C+E)){
		
		rep(i, 0, C+2) adj[i].clear();
		
		int u, v, c;
		rep(i, 0, E){
			scanf("%d %d %d", &u, &v, &c);
			adj[u].pb(ii(v, c));
			adj[v].pb(ii(u, c));
		}
		
		scanf("%d", &u);
		vector <int> distance(C+2, 0x3f3f3f3f), pai(C+2, -1);
		int ans = 0x3f3f3f3f; vector <int> way;
		priority_queue <ii> pq; pq.push(ii(0, u)); distance[u] = 0;
		
		while(!pq.empty()){
			u = pq.top().S, c = -pq.top().F; pq.pop();
			if(u==1){
				while(pai[u]!=-1){
					way.pb(u);
					u = pai[u];
				}	way.pb(u);
				reverse(way.begin(), way.end());
				ans = c;
				break;
			}
			rep(i, 0, adj[u].size()){
				int v = adj[u][i].F,
					cc = adj[u][i].S;
				if(distance[v]<=distance[u]+cc) continue;
				distance[v]=distance[u]+cc;
				pai[v] = u;
				pq.push(ii(-distance[v], v));
			}
		}
		
		if(ans<=120){
			printf("Will not be late. Travel time - %d - best way -", ans);
			rep(i, 0, way.size()) printf(" %d", way[i]);
		}else{
			printf("It will be %d minutes late. Travel time - %d - best way -", ans-120, ans);
			rep(i, 0, way.size()) printf(" %d", way[i]);
		}
		printf("\n");
	}
	
	
	return 0;
}
