// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cidade Proibida
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2528

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ll, ii > iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;

int N, M, C, R, E;
vector <int> adj[1010];
int vis[1010];

int sol(){
	queue <ii> q;
	q.push(mp(C, 0)); vis[C]=1;
	
	while(!q.empty()){
		int u=q.front().F, t=q.front().S; q.pop();
		
		if(u==R) return t;
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(vis[v]) continue;
			vis[v]=1;
			q.push(mp(v, t+1));
		}
	}
	
	return -1;
	
}
int main(){
	
	while(scanf("%d %d", &N, &M) !=EOF){
		
		rep(i, 1, N+2){
			vis[i]=0;
			adj[i].clear();
		}
		
		int u, v;
		rep(i, 0, M){
			scanf("%d %d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		scanf("%d %d %d", &C, &R, &E);
		vis[E]=1;
		
		printf("%d\n", sol());
		
	}
	
	return 0;
	
}
