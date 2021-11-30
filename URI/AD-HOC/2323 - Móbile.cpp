// Author: Gustavo Policarpo
// Name: Móbile
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2323

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
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;



vector <int> adj[10010];
int n, yep=1, cnt[10010];

int dfs(int u, int last){
	cnt[u]=1;
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(v==last) continue;
		cnt[u]+=dfs(v, u);
	}
	return cnt[u];
}

void check(int u, int last){
	if(!yep) return;
	int son=adj[u][0];
	if(son==last) son=adj[u][1];
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(v==last) continue;
		if(cnt[v]!=cnt[son]){
			yep=0;
			return;
		}
	}
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(v==last) continue;
		check(v, u);
	}
	return;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
    scanf("%d", &n);
    int u, v;
    rep(i, 0, n){
    	scanf("%d %d", &u, &v);
    	adj[u].pb(v);
    	adj[v].pb(u);
	}
	
	yep=1;
	dfs(0, 0);
	check(0, 0);
	
	yep ? puts("bem") : puts("mal");
	
    return 0;
    
}
