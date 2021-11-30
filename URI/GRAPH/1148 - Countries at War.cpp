// Author: Gustavo Policarpo
// Name: Countries at War
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1148

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#include<bits/stdc++.h>

#define pb push_back
#define all(v)  (v).begin(), (v).end()
#define INF 0x3f3f3f
#define F first
#define S second
#define rep( i, a, b ) for( int i = a; i < b; i++ )

typedef long long int ll;
typedef pair < int, int > ii;

int mat[501][501];

const int MAXV = 1000; 

int dist[MAXV], pai[MAXV];
vector<ii> adj[MAXV];   

int dijkstra( int ini, int fim ){
    
    memset( dist, INF, sizeof dist );
    memset( pai, -1, sizeof pai );
    dist[ini] = 0;
    priority_queue<ii> pq;
    pq.push( ii( 0, ini ) );
    
    while( !pq.empty() ){
        int u = pq.top().S;
        int c = -pq.top().F;
        pq.pop();
        if( dist[u] != c ) continue;
        rep( i, 0, adj[u].size() ){
            int v = adj[u][i].F;
            int d_u_v = adj[u][i].S;
            if( dist[v] > d_u_v + c ){
                dist[v] = d_u_v + c;
                pai[v] = u;
                pq.push( ii(-dist[v], v ) );
            }
        }
    }
    return dist[fim];
}

void tozero(int n)
{
	rep(i, 0, n+1)
		adj[i].clear();
		//vis[i]=0;
		//dist[i]=0;
	memset(mat, 0, sizeof(mat));	
}
int main()
{
	int N, E;
	while(cin >> N >> E && N+E){
		tozero(N);
		int x, y, c;
		while(E--){
			scanf("%d %d %d", &x, &y, &c);
			mat[x][y]=c;
		}
		rep(i, 1, N+1)
			rep(j, i+1, N+1){
				if(mat[i][j]>0&&mat[j][i]>0){
					adj[i].pb(ii(j, 0));
					adj[j].pb(ii(i, 0));
				}
				else if(mat[i][j]>0)
					adj[i].pb(ii(j, mat[i][j]));	
				else if(mat[j][i]>0)
					adj[j].pb(ii(i, mat[j][i]));	
			}
			
		int K; cin >> K;
		while(K--){
			scanf("%d %d", &x, &y);
			int dist=dijkstra(x, y);
			if(dist>=INF) cout << "Nao e possivel entregar a carta";
			else cout << dist;
			cout << endl;
		}
		cout << endl;
		
	}
return (0);
}
