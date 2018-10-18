// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Detectando Pontes
// Nível: 2
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1790

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

vector <int> adj[51];
int mat[51][51];
int vis[51]; int out, cont;

void dfs(int u, int x, int y)
{
	vis[u]=1;
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(u==x&&v==y || u==y&&v==x || vis[v]==1) ;
		else	dfs(v, x, y);
	}	
}
void tozero(int n)
{
	rep(i, 1, n+1){
		vis[i]=0;
		adj[i].clear();
	}
	memset(mat, 0, sizeof(mat));
}
int main()
{
	int C, P;
	while(cin >> C >> P){
		tozero(C);
		int x, y;
		rep(i, 0, P){
			scanf("%d %d", &x, &y);
			adj[y].pb(x);adj[x].pb(y);
			mat[x][y]=1; mat[y][x]=1;	
		}
		int res=0, cont=0;
		rep(i, 1, C+1){
			rep(j, 1, i){
				if(mat[i][j]==1){
						dfs(i, i, j);
						
					rep(z, 1, C+1) if(vis[z]==1) cont++;
					if(cont==C)	res++;
					
					cont=0;
					memset(vis, 0, sizeof(vis));
				}
			}
		}
		cout << P-res << endl;			
	}
return 0;
}
