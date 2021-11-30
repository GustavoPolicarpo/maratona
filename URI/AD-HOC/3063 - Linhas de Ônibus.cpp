// Author: Gustavo Policarpo
// Name: Linhas de Ônibus
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3063

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define per(i,a,b) for( int i = (int) a; i > (int) b; i-- )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int MAX = 2e3+3;
const int mod = 1e9+7;

int T, L, O, D;
int mat[505][505];
vector <int> adj[505];
vector <int> lin[505];

int bfs(){
    int dist[505][505]; memset(dist, 0x3f3f3f3f, sizeof dist);
    priority_queue <iii> pq;
    rep(i, 0, adj[O].size()){
        int u = adj[O][i];
        dist[O][u] = 0;
        pq.push(iii(0, ii(O, u)));
    }


    while(!pq.empty()){
        int d = -pq.top().F, u = pq.top().S.F, l = pq.top().S.S; pq.pop();
        if(u==D) return d;
        for(auto v : lin[l]){
            if(dist[v][l]<=dist[u][l]) continue;
            dist[v][l] = dist[u][l];
            pq.push(iii(-dist[v][l], ii(v, l)));
        }
        for(auto v : adj[u]){
            if(dist[u][v]<=dist[u][l]) continue;
            dist[u][v] = dist[u][l]+1;
            pq.push(iii(-dist[u][v], ii(u, v)));
        }
    }
}

int main(){

    scanf("%d %d %d %d", &T, &L, &O, &D);
    O--, D--;
    rep(i, 0, L){
        int qt, u; scanf("%d", &qt);
        rep(j, 0, qt){
            scanf("%d", &u);
            u--;
            lin[i].pb(u);
            adj[u].pb(i);
        }
        rep(j, 0, qt) rep(k, j+1, qt){
            mat[lin[i][j]][lin[i][k]] = 1;
            mat[lin[i][k]][lin[i][j]] = 1;
        }
    }

    printf("%d\n", bfs()+1);



    return  0;
}
