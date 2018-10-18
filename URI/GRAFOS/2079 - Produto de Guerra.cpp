// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Produto de Guerra
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2079

#define gc getchar_unlocked
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
typedef pair < int, string > ii;
typedef pair < double, int > iii;
 
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

int N, pd[6001][3];
vector <int> adj[6001];
vector <int> go[6001];

void dfs(int u, int last){
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(v==last) continue;
		go[u].pb(v);
		dfs(v, u);
	}
	return;
}

int solve(int u, int op){
	if(pd[u][op]!=-1) return pd[u][op];
	int ret=0;
	if(op==0){
		rep(i, 0, go[u].size()){
			int v=go[u][i], aux=0;
			aux=max(aux, max(solve(v, 1)+1, solve(v, 2)));
			ret+=aux;
		}
	}
	else if(op==1){
		rep(i, 0, go[u].size()){
			int v=go[u][i];
			ret+=solve(v, 0);
		}
	}
	else{
		rep(i, 0, go[u].size()){
			int v=go[u][i];
			if(adj[v].size()==1) ret+=solve(v, 1)+1;
			else ret+=(max(solve(v, 2), solve(v, 1)+1));	
		}
	}
	return pd[u][op]=ret;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T; cin >> T;
	while(T--){
		scanint(N);
		rep(i, 1, N+1) adj[i].clear(), go[i].clear();
		memset(pd, -1, sizeof pd);
		int u, v;
		rep(i, 1, N){
			scanint(u), scanint(v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		dfs(1, 1);
		int out=max(solve(1, 1)+1, solve(1, 2));
		printf("%d\n", out);
	}
		
return (0);	
} 
