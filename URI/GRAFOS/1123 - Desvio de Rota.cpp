// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Desvio de Rota
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1123

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
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

vector < ii > adj[501];
int dist[501];
int dist2[501];

int N, M, C, K;

int out;
int dijkstra(int x, int y)
{
    memset(dist2, INF, sizeof(dist2));
    dist2[x]=0;

    priority_queue <ii> pq;
    pq.push(mp(dist2[x], x));

    while(!pq.empty()){
        int u=pq.top().second, d=-pq.top().first;
        pq.pop();
        if(u==C-1){
            out=min(out, d);
            continue;
        }
        else if(u<C-1){
            out=min(out, d+dist[u]);
            continue;
        }

        if(d!=dist2[u]) continue;
        //if(u==y) break;
        rep(i, 0, adj[u].size()){
            int v=adj[u][i].first;
            int c=adj[u][i].second;
            if(dist2[v]>dist2[u]+c){
                dist2[v]=dist2[u]+c;
                pq.push(mp(-dist2[v], v));
            }
        }
    }
}
int mat[260][260];
int main()
{
    while(scanf("%d %d %d %d", &N, &M, &C, &K) and N+M+C+K){
        int u, v, c; out=INF;
        memset(mat, 0, sizeof mat);
        rep(i, 0, N+1) adj[i].clear();
        rep(i, 0, M){
            scanf("%d %d %d", &u, &v, &c);
            adj[u].pb(mp(v, c));
            adj[v].pb(mp(u, c));
            mat[u][v]=c;
            mat[v][u]=c;
        }
        dist[C-1]=0;
        for(int i=C-2; i>=0; i--)
            dist[i]=dist[i+1]+mat[i][i+1];// cout << i << " " << mat[i][i+1] << endl;
        //rep(i, 0, C)
         //   cout << dist[i] << endl;
        dijkstra(K, C-1);
        cout << out << endl;
    }

return 0;
}

