// Author: Gustavo Policarpo
// Name: Dabriel and Your Party
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2841

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

int n;
vector <int> adj[100010];
int x[100010], pd[100010][2];

int solve(int u, int op, int last){
	//if(adj[u].size()==1) return 0; 
	if(pd[u][op]!=-1) return pd[u][op];
	
	int ret = 0;
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		if(v==last) continue;
		int aux = solve(v, 0, u);
		if(op==0) aux = max(aux, solve(v, 1, u)+x[v]);
		ret += aux;
	}
	
	return pd[u][op] = ret;
}

int main(){
	
	scanf("%d", &n)	;
	rep(i, 0, n) scanf("%d", &x[i+1]);
	
	int u;
	rep(i, 1, n){
		scanf("%d", &u);
		adj[i+1].pb(u);
		adj[u].pb(i+1);
	}
	
	memset(pd, -1, sizeof pd);
	printf("%d\n", max(solve(1, 0, 1), solve(1, 1, 1)+x[1]));
	
	return 0;
} 
