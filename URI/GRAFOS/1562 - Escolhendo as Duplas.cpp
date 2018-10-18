// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Escolhendo as Duplas
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1562

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned long long int ull;
typedef pair < int, ll > ii;
typedef pair < double, int > iii;


vector <int> adj[10010], adj2[10010]; 
int vis[10010], par[10010], grau[10010], cnt;

struct use{
	int grau, ver;
	
	bool operator() (use a, use b){
		
		if(a.grau==0 && b.grau==0){
			if(a.ver < b.ver) return false;
			if(a.ver > b.ver) return true;
		}
		
		if(a.grau == 0) return false;
		if(b.grau == 0) return true;
		
		if(a.ver < b.ver) return false;
		if(a.ver > b.ver) return true;
	}
};

void solve(int N){
	
	priority_queue <use, vector <use>, use> pq; cnt=0;
	use aux;
	
	rep(i, 1, N+1){
		aux.grau=grau[i], 
		aux.ver=i;
		pq.push(aux);
	}
	
	while(!pq.empty()){
		int u=pq.top().ver; pq.pop();
		
		int v = adj[u][0];
		
		if(par[u] || par[v]) continue;
		
		grau[u]=grau[v]=-1;
		par[u]=v, 
		par[v]=u;
		cnt+=2;
		grau[adj[v][0]]--;
		
		aux.grau=grau[adj[v][0]],
		aux.ver=adj[v][0];
		if(!par[aux.ver])
			pq.push(aux);
		
	}
		
	return;
	
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N, aux, yep; 
	
	while(scanf("%d", &N) !=EOF){
		
		rep(i, 1, N+1){
			adj[i].clear(), 
			adj2[i].clear(), 
			vis[i]=par[i]=grau[i]=0;
		}	cnt=0;
		
		rep(i, 1, N+1){
			scanf("%d", &aux);
			adj[i].pb(aux);
			adj2[aux].pb(i);
			grau[aux]++;
		}
		
		solve(N);
		
		yep=1;
		rep(i, 1, N+1){
			if(!par[i]){
				yep=false;
				break;
			}
		}
		
		
		if(!yep){
			puts("IMPOSSIBLE");
			continue;
		}
		
		rep(i, 1, N+1){
			if(i-1) printf(" ");
			printf("%d", par[i]);
		}	printf("\n");
		
	}

	return 0;
	
}
