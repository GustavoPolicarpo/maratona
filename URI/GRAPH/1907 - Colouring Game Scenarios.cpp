// Author: Gustavo Policarpo
// Name: Colouring Game Scenarios
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1907

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

int vis[1025][1025];
char Q[1025][1025];
int N, M;

int bfs(int x, int y)
{
	queue <ii> q;
	q.push(mp(x, y));
	while(!q.empty()){
		x=q.front().first;
		y=q.front().second;
		q.pop();
		if(vis[x][y]!=1){
			vis[x][y]=1;
			
			if(x>0)
				if(vis[x-1][y]==0 and Q[x-1][y]=='.')
					q.push(mp(x-1, y));
			if(y>0)
				if(vis[x][y-1]==0 and Q[x][y-1]=='.')
					q.push(mp(x, y-1));
			if(x<N-1)
				if(vis[x+1][y]==0 and Q[x+1][y]=='.')
					q.push(mp(x+1, y));
			if(y<M-1)
				if(vis[x][y+1]==0 and Q[x][y+1]=='.')
					q.push(mp(x, y+1));
		}
	}		
}

int main()
{
	cin >> N >> M;
	
	memset(vis, 0, sizeof(vis));
	
	rep(i, 0, N)
		rep(j, 0, M)
			cin >> Q[i][j];
	
	int cont=0;
	rep(i, 0, N)
		rep(j, 0, M)
			if(vis[i][j]!=1&&Q[i][j]=='.'){
				bfs(i, j);
				cont++;
			}
	cout << cont << endl;	
							
return (0);
}
