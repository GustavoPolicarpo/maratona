// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Grupos Sanguineos
// Nível: 6
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2014

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

int N, M, match[202], vis[101];
vector <int> adj[101];

int aug(int u){
	if(vis[u]) return 0;
	vis[u]=1;
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(match[v]==-1 || aug(match[v])){
			match[v]=u;
			return 1;
		}
	}
	return 0;
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N, Q, q, aux, hasall=0;
	scanint(N), scanint(Q);
	
	set <int> n[N];
	rep(i, 0, N){
		scanint(q);
		if(q==N) hasall=1;
		while(q--){
			scanint(aux); aux--;
			n[i].insert(aux);
		}
	}
	
	while(Q--){
		scanint(q);
		if(q==0){
			puts( hasall ? "N" : "Y");
			continue;
		}
		
		rep(i, 0, N) adj[i].clear(), match[i]=-1;
		rep(i, N, 2*N + 1) match[i]=-1;
		
		rep(k, 0, q){
			scanint(aux); aux--;
			rep(i, 0, N){
				if(n[i].count(aux))
					adj[i].pb(N+aux);
			}
		}
		
		int mcbm=0;
		rep(i, 0, N){
			rep(j, 0, N) vis[j]=0;
			mcbm+=aug(i);
		}
	
		puts( mcbm==q ? "Y" : "N");
		
	}

	return 0;

}



