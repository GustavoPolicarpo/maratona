// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Robô Aspirador
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2558

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < ii, int > iii;

int N, M, L, C, dst[10][10], vis[111][111], pd[10][1<<10+2][2002];
int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};
char mat[111][111];
map<ii, int> mapa;

bool dentro(int x, int y){
	return x>=0 && y>=0 && x<L && y<C && mat[x][y]!='#' && !vis[x][y];
}

void bfs(int xx, int yy){
	
	rep(i, 0, L+2) rep(j, 0, C+2) vis[i][j]=0;
	
	queue <iii> q;
	q.push(mp(mp(xx, yy), 0)); vis[xx][yy]=1;
	
	while(!q.empty()){
		int x=q.front().F.F, y=q.front().F.S, c=q.front().S; q.pop();
		
		if(c>M) break;
		if(mapa.count(ii(x, y))) dst[mapa[ii(xx, yy)]][mapa[ii(x, y)]]=c;
		
		rep(i, 0, 4){
			int ax=x+dx[i], ay=y+dy[i];
			if(!dentro(ax, ay)) continue;
			vis[ax][ay]=1;
			q.push(mp(mp(ax, ay), c+1));
		}
		
	}
}

int solve(int p, int mask, int d){
	
	if(p==N+1) return 0;
	if(pd[p][mask][d]!=-1) return pd[p][mask][d];
	
	int ret=-INF;
	rep(i, 1, N+2){
		if(!(mask&(1<<i)) && d+dst[p][i]<=M){
			ret=max(ret, solve(i, mask|(1<<i), d+dst[p][i])+1);
		}
	}
	
	return pd[p][mask][d]=ret;
}
int main()
{
	
	while(scanf("%d %d %d %d ", &N, &M, &C, &L)!=EOF){
		
		int cnt=1; mapa.clear();
		rep(i, 0, L){
			gets(mat[i]);
			rep(j, 0, C){
				if(mat[i][j]=='*') mapa[ii(i, j)]=cnt++;
				else if(mat[i][j]=='S') mapa[ii(i, j)]=0;
				else if(mat[i][j]=='R') mapa[ii(i, j)]=N+1;
			}
		}
		
		memset(dst, INF, sizeof dst);
		rep(i, 0, L)
		rep(j, 0, C)
		if(mapa.count(ii(i, j))) bfs(i, j);
		
		/*rep(i, 0, cnt+1){
			rep(j, 0, cnt+1){
				cout << dst[i][j] << " ";
			}
			cout << '\n';
		}*/
		
		if(dst[0][N+1]>M){
			puts("-1");
			continue;
		}
		
		rep(i, 0, N+2) rep(j, 0, 1<<(N+1)+2) rep(k, 0, (L+C)*(N+2)) pd[i][j][k]=-1;
		
		printf("%d\n", solve(0, 1<<0, 0)-1);
		
	}
	
	return 0;
	
}
