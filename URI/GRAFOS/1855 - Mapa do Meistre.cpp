// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Mapa do Meistre
// Nível: 2
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1855

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

char mapa[101][101];
map <char, ii> dir;
int vis[101][101];
int L, C;

bool dentro(int x, int y)
{
	if(x>=1 && y>=1 && x<=L && y<=C)
		return true;
	return false;
}
char g; int gox, goy;
bool dfs(int x, int y)
{
	g=mapa[x][y];
	//cout << x << " " << y << endl;
	if(g=='*') return true;
	if(!dentro(x, y)) return false;
	if(dir.count(g)){
		if(vis[x][y]==1) return false;
		gox=dir[g].first;
		goy=dir[g].second;
	}
	vis[x][y]=1;
	dfs(x+gox, y+goy);
}


int main()
{
	memset(vis, 0, sizeof(vis));
	dir['>']=mp(0,1);
	dir['<']=mp(0,-1);
	dir['v']=mp(1,0);
	dir['^']=mp(-1,0);
	
	cin >> C >> L;
	
	rep(i, 1, L+1)
		rep(j, 1, C+1)
			cin >> mapa[i][j];
	
	bool found=dfs(1, 1);
	if(found) cout << '*';
	else	  cout << '!';
	cout << endl;
		
return 0;
}
