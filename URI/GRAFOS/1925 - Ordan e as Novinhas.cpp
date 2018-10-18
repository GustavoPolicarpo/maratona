// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ordan e as Novinhas
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1925

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




char mat[1001][1001]; 
int vis[1001][1001], val[1001][1001], id[1001][1001], 
	dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0}, l, c;
vector <ii> pas;


bool go(int x, int y){
	return x>=0 && y>=0 && x<l && y<c && vis[x][y]==0 && mat[x][y]=='n';
}
void dfs(int x, int y){
	if(vis[x][y]) return;
	pas.pb(mp(x, y)), vis[x][y]=1;
	
	rep(i, 0, 4){
		int ax=x+dx[i], ay=y+dy[i];
		if(!go(ax, ay)) continue;
		dfs(ax, ay);
	}
	
	return;
	
}
int main()
{
	scanf("%d %d", &l, &c);
	
	rep(i, 0, l)
	rep(j, 0, c) 
		scanf(" %c", &mat[i][j]);
		
	
	int ranki=0;
	rep(i, 0, l)
	rep(j, 0, c){
		if(mat[i][j]=='n' && !vis[i][j]){
			int t=pas.size();
			rep(k, 0, t) val[pas[k].F][pas[k].S]=t, id[pas[k].F][pas[k].S]=ranki;
			pas.clear(); ranki++;
			dfs(i, j);
		}
	}
	
	int t=pas.size();
	rep(k, 0, t) val[pas[k].F][pas[k].S]=t;
	pas.clear();
	
	int maior=0, xx=0, yy=0;
		
	rep(i, 0, l)
	rep(j, 0, c){
		if(mat[i][j]=='*'){
			int aux=0; set <int> use;
			rep(k, 0, 4){
				int ax=i+dx[k], ay=j+dy[k];
				if(ax>=0 && ay>=0 && ax<l && ay<c && val[ax][ay])
					if(!use.count(id[ax][ay])) aux+=val[ax][ay], use.insert(id[ax][ay]);
				
			}
			if(aux>maior)
				maior=aux, xx=i, yy=j;
		}
	}
	
	//cout << maior << '\n';
	printf("%d,%d\n", xx+1, yy+1);

		
	

	return 0;
}



