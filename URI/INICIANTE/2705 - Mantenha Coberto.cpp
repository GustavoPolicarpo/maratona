// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Mantenha Coberto
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2705

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;



char mat[22][22];
vector <int> adj[808];
int R, C;
int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};
int match[1616], vis[808];


bool dentro(int x, int y){
	return x>=0 && y>=0 && x<R && y<C;
}

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
	
	cin >> R >> C;
	rep(i, 0, R) rep(j, 0, C) cin >> mat[i][j];
	
	rep(x, 0, R) rep(y, 0, C) rep(i, 0, 4){
		
		int ax = x+dx[i], ay = y+dy[i];
		if(!dentro(ax, ay)) continue;
		
		int u[2], v[2];
		u[0] = x*C+y, v[0] = ax*C+ay;
		mat[x][y]!='o' ? u[1] = R*C+x*C+y : u[1] = -1;
		mat[ax][ay]!='o' ? v[1] = R*C+ax*C+ay : v[1] = -1;
		
		rep(a, 0, 2){
			if(u[a]==-1) continue;
			rep(b, 0, 2){
				if(v[b]==-1) continue;
				adj[u[a]].pb(v[b]);
			}
		}
	}
	 	
	int mcbm = 0;
	memset(match, -1, sizeof match);
	rep(i, 0, R*C+R*C){
		memset(vis, 0, sizeof vis);
		mcbm+=aug(i);
	}
	
	int ret = 0;
	rep(i, 0, R) rep(j, 0, C) ret+=(mat[i][j]=='o');
	int total = (R*C-ret)*2 + ret;
	
	if(mcbm==total) puts("Y");
	else puts("N");
	
	return 0;
	
}
