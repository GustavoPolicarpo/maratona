// Author: Gustavo Policarpo
// Name: Christmas Tree
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2575

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <double, int> ii;

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
#define EPS 1e-9

struct use{
	int v, id, c;
};

int N;
vector <use> adj[1000010];
bool mark[1000010];

int dfs(int u, int last){
	
	int ret=0;
	
	rep(i, 0, adj[u].size()){
		int v=adj[u][i].v,
			c=adj[u][i].c,
			id=adj[u][i].id;
		if(v==last) continue;
		
		int aux=dfs(v, u)+c;
		if(aux<=0){
			mark[id]=true;
		}else{
			ret+=aux;
		}
	}
	
	return ret;
	
}

vector <int> rev;
void solve(int u, int last){
	rep(i, 0, adj[u].size()){
		int v=adj[u][i].v,
			c=adj[u][i].c,
			id=adj[u][i].id;
		if(v==last) continue;
		if(mark[id]){
			rev.pb(id);
		}else{
			solve(v, u);
		}
	}
}


int main(){
	
	scanf("%d", &N);
	
	int u; use aux;
	rep(i, 1, N){
		scanf("%d %d %d %d", &aux.id, &u, &aux.v, &aux.c);
		adj[u].pb(aux); swap(u, aux.v);
		adj[u].pb(aux); swap(u, aux.v);
	}
	
	int ans=dfs(0, 0);
	solve(0, 0); sort(rev.begin(), rev.end());
	
	printf("%d %d\n", ans, rev.size());
	if(rev.size()){
		rep(i, 0, rev.size()){
			if(i) printf(" ");
			printf("%d", rev[i]);
		}
		printf("\n");
	}
	
	
	return 0;
	
}
