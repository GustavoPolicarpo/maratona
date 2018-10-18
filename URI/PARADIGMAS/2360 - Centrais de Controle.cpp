// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Centrais de Controle
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2360

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

int N;
ll pd[1010][4][2];
vector <int> adjin[1010], adj[1010], adj2[1010];

ll solve(int u, int c, int cc){
	
	ll &ret=pd[u][c][cc];
    if(ret!=-1) return ret;
    
    ret=0;
    
    if(adj[u].size()==0 && adj2[u].size()==0){
    	if(c==0) return ret=1;
    	else return ret=(cc==0);
	}
	
    if(adj[u].size()==0){ 
        if(cc==0) ret=solve(adj2[u][0], min(c, 1), 0)+solve(adj2[u][0], min(c, 1), 1);
        if(cc==1 && c==0) ret=solve(adj2[u][0], min(c, 1), 0)+solve(adj2[u][0], min(c, c), 1);
    }
    
    else if(adj2[u].size()==0){ int v=adj[u][0];
    	if(cc==0) ret=solve(v, 0, 0)+solve(v, 0, 1);
    	if(cc==1 && c<2) ret=solve(v, min(c+1, 1), 0)+solve(v, min(c+1, 2), 1);
    }
	
	else{ int v=adj[u][0];
        if(cc==0) ret=solve(v, 0, 0)*solve(adj2[u][0], min(c, 1), 0)+
        			   solve(v, 0, 0)*solve(adj2[u][0], min(c, 1), 1)+
        			    solve(v, 0, 1)*solve(adj2[u][0], min(c, 1), 0)+
        			     solve(v, 0, 1)*solve(adj2[u][0], min(c, 1), 1);
        if(cc==1) ret=solve(v, min(c+1, 1), 0)*solve(adj2[u][0], min(c, 1), 0)+
        			   solve(v, min(c+1, 1), 0)*solve(adj2[u][0], min(c, c), 1)+
        			    solve(v, min(c+1, 2), 1)*solve(adj2[u][0], min(c, 1), 0)+
        			     solve(v, min(c+1, 2), 1)*solve(adj2[u][0], min(c, c), 1);
    }
    
    if(ret >= mod) ret%=mod;
    return ret;
}

void dfs(int u, int last){
	int uv=0;
    rep(i, 0, adjin[u].size()){
        int v=adjin[u][i];
        if(v==last) continue;
        adj[u].pb(v), adj2[uv].pb(v), uv=v;
        dfs(v, u);
    }
}

int main(){
    
    while(scanf("%d", &N) !=EOF){
        
        rep(i, 0, N+2){
        	adjin[i].clear();
            adj[i].clear();
            adj2[i].clear();
            rep(j, 0, 4) rep(k, 0, 2)
                pd[i][j][k]=-1;
        }
        
        int u, v;
        rep(i, 0, N-1){
            scanf("%d %d", &u, &v);
            adjin[u].pb(v);
            adjin[v].pb(u);
        }
        
        dfs(1, 1);
        
        printf("%lld\n", (solve(1, 1, 0)+solve(1, 1, 1))%mod);
        
    }
        
    return 0;   
}

