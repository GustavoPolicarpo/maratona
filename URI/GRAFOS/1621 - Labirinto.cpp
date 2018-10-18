// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Labirinto
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1621

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F3F

typedef  long long int ll;
typedef pair < int, int > ii;
typedef pair < ii, int > iii;

char lab[501][501];
int vis[501][501];
ll dist;
int N, M;

char dx[] = {-1, 0, 0, 1};
char dy[] = {0, -1, 1, 0};

bool dentro(int x, int y)
{
	return x>=0 && x<N && y>=0 && y<M;
}

ii bfs(int x, int y)
{
	queue < iii > q;
	q.push(mp (mp(x , y) , 0) );
	ii ret;
	while(!q.empty()){
		
		ii u=q.front().first;
		x=u.first; y=u.second;
		dist=q.front().second;
		q.pop();
		
			//cout << x << " " << y << endl;
			
		vis[x][y]=1;
		ret=mp(x, y);
		
		rep(i, 0, 4){
			int X=x+dx[i], Y=y+dy[i];
			if(dentro(X, Y)&&lab[X][Y]=='.'&&vis[X][Y]!=1)
				q.push(mp (mp(X , Y) , dist+1) );
		}	
	}
	return ret;		
}
int main()
{
	while(cin >> N >> M && N+M){
		ii c1;
		rep(i, 0, N)
			rep(j, 0, M){
				cin >> lab[i][j];
				if(lab[i][j]=='.')
					c1=mp(i, j);
				}
		dist=0;	
		memset(vis, 0, sizeof(vis));	
		ii c2=bfs(c1.first , c1.second);
		//cout << "        " << c2.first << " " << c2.second << endl;
		dist=0;
		memset(vis, 0, sizeof(vis));
		bfs(c2.first , c2.second);
		
		cout << dist << endl;
			
	}	
	
return 0;		
}
