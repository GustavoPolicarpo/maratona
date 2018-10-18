// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Junte Dois Reinos
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1499

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
typedef pair<ii, int> iii;

const ll mod = 1e9+7;

vector <ll> dist[2], adj[40040][2], sum[2];
ll N, M, r[2], d[4], maior, pai[40040][20][2], h[40040][2];

void dfs(int u, int op, int t, int last){
    dist[op][u] = t;
    if(t >= r[op]) r[op] = t, d[op] = u;
    rep(i, 0, adj[u][op].size()){
        int v=adj[u][op][i];
        if(v==last) continue;
        dfs(v, op, t+1, u);
    }
    return;
}

void dfs_lca(int u, int op, int last){
    rep(i, 0, adj[u][op].size()){
        int v=adj[u][op][i];
        if(v==last) continue;
        h[v][op]=h[u][op]+1, pai[v][0][op]=u;
        rep(j, 1, 20) pai[v][j][op] = pai[pai[v][j-1][op]][j-1][op];
        dfs_lca(v, op, u);
    }
}

int get_dist(int u, int v, int op){

	if(u==v) return 0;
	if(h[u][op] < h[v][op]) swap(u, v);
	int a=u, b=v;
	
	for(int i=19; i>=0; i--) if(h[pai[a][i][op]][op] >= h[b][op]) a=pai[a][i][op];
	if(a==b) return h[u][op] + h[v][op] - 2*h[a][op];
	for(int i=19; i>=0; i--) if(pai[a][i][op] != pai[b][i][op]) a=pai[a][i][op], b=pai[b][i][op];
	return h[u][op]+h[v][op]-2*h[pai[a][0][op]][op];
}

int main(){

    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    
    while(scanf("%lld %lld", &N, &M)!=EOF){
        
        dist[0].resize(N, 0);
        dist[1].resize(M, 0);
        sum[0].resize(N, 0);
        sum[1].resize(M, 0);
        
        rep(i, 0, N) adj[i][0].clear();
        rep(i, 0, M) adj[i][1].clear();
        
        int u, v;
        rep(i, 1, N){
            scanf("%d %d", &u, &v); u--, v--;
            adj[u][0].pb(v);
            adj[v][0].pb(u);
        }
        rep(i, 1, M){
            scanf("%d %d", &u, &v); u--, v--;
            adj[u][1].pb(v);
            adj[v][1].pb(u);
        }
        
        r[0] = r[1] = -1;
        dfs(0, 0, 0, 0); d[2]=d[0];
        dfs(d[0], 0, 0, d[0]);
        dfs(0, 1, 0, 0); d[3]=d[1];
        dfs(d[1], 1, 0, d[1]);
        
        h[d[0]][0] = 0; rep(i, 0, 20) pai[d[0]][i][0]=d[0];
        dfs_lca(d[0], 0, d[0]);
        h[d[1]][1] = 0; rep(i, 0, 20) pai[d[1]][i][1]=d[1];
        dfs_lca(d[1], 1, d[1]);
        
        rep(i, 0, N) dist[0][i] = max(get_dist(i, d[0], 0), get_dist(i, d[2], 0));
        rep(i, 0, M) dist[1][i] = max(get_dist(i, d[1], 1), get_dist(i, d[3], 1));
        
        
        
        sort(dist[0].begin(), dist[0].end());
        sort(dist[1].begin(), dist[1].end());
		
		//rep(i, 0, N) cout << dist[0][i] << " "; cout << '\n';
        //rep(i, 0, M) cout << dist[1][i] << " "; cout << '\n';
        
        sum[0][0]=dist[0][0];
        rep(i, 1, N) sum[0][i] = sum[0][i-1]+dist[0][i];
        sum[1][0]=dist[1][0];
        rep(i, 1, M) sum[1][i] = sum[1][i-1]+dist[1][i];
        
        long double ans = 0.0; int pointer = M-1; maior = max(r[0], r[1]);
        
        rep(i, 0, N){
            while(pointer>=0 && dist[0][i]+dist[1][pointer]+1 >= maior) pointer--;
            if(pointer == -1){
                ans = ans + dist[0][i]*M + sum[1][M-1] + M;
            }else{
                ans = ans + dist[0][i]*(M-(pointer+1)) + maior*(pointer+1) + sum[1][M-1] - sum[1][pointer] + M - (pointer+1);
            }
        }
        
        ans = ans/(N*M);
        
        printf("%.3LF\n", ans);
        
    }
    
    return 0;   
}
