// Author: Gustavo Policarpo
// Name: Transmissão de Energia
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2300

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


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;




vector <int> adj[101];
int vis[101];

void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;
	
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(!vis[v])
			dfs(v);
	}
	
	return;
}
int main(){
	
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N, M, z=1;
	while(1){
		scanint(N), scanint(M);
		if(!N) break;
		rep(i, 1, N+1){
			adj[i].clear();
			vis[i]=0;
		}
		
		int u, v;
		rep(i, 0, M){
			scanint(u), scanint(v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		dfs(1);
		
		bool yep=true;
		rep(i, 1, N+1){
			if(!vis[i]){
				yep=false;
				break;
			}
		}
		
		printf("Teste %d\n", z++);
		printf("%s\n\n", yep ? "normal" : "falha");
	}
	
}

