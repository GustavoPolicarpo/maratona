// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Dona Minhoca
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1711

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

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
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

const int MAXV=10010;
vector <ii> adj[MAXV];
int tam_ciclo[MAXV], vis[MAXV], pai[MAXV], N, M, Q;
map <ii, int> custo;

void dfs(int u){
	
	vis[u]=2;
	int tam=adj[u].size();
	
	rep(i, 0, tam){
		int v=adj[u][i].F; 
		if(v==pai[u]) continue;
		pai[v]=u;
		
		if(vis[v]==2){
			vector <int> S; S.pb(v);
			int vv=u; tam_ciclo[v]+=custo[ii(v, vv)];
			while(vv!=v){
				S.pb(vv);
				tam_ciclo[v]+=custo[ii(vv, pai[vv])];
				vv=pai[vv];
			}
			rep(j, 0, S.size())
				tam_ciclo[S[j]]=tam_ciclo[v];			
		}
		
		else if(vis[v]==0) 
			dfs(v);
	}
	
	vis[u]=1;
}

int dist[MAXV];
int menor_caminho(int u, int c){
	
	int ret=INF;
	if(tam_ciclo[u]>=c)	ret=tam_ciclo[u];
	
	rep(i, 1, N+1) dist[i]=INF;
	
	priority_queue <ii> pq;
	rep(i, 1, N+1) dist[i]=INF;
	pq.push(mp(0, u)); dist[u]=0;
	
	while(!pq.empty()){
		int u=pq.top().S, d=-pq.top().F, tam=adj[u].size(); pq.pop();
		
		rep(i, 0, tam){
			int v=adj[u][i].F, cc=adj[u][i].S;
			if(tam_ciclo[v]!=0){
				if(tam_ciclo[v]>=c)
					ret=min(ret, 2*(d+cc)+tam_ciclo[v]);
			}
			if(dist[v]>=d+cc){
				dist[v]=d+cc;
				pq.push(mp(-dist[v], v));
			}
		}
	}
	
	if(ret==INF) return -1;
	return ret;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(scanf("%d %d", &N, &M) !=EOF){
		
		rep(i, 0, N+1){
			tam_ciclo[i] = vis[i] = pai[i] = 0;
			adj[i].clear();
		} 
		
		int u, v, c;
		rep(i, 0, M){
			scanint(u), scanint(v), scanint(c);
			adj[u].pb(mp(v, c));
			adj[v].pb(mp(u, c));
			custo[ii(u, v)] = custo[ii(v, u)] = c;
		}
		
		rep(i, 1, N+1){
			if(vis[i]==0){
				dfs(i);
			}
		}
		
		scanint(Q);
		
		while(Q--){
			scanint(u), scanint(c);
			printf("%d\n", menor_caminho(u, c));
		}
		
	}



return 0;
}
