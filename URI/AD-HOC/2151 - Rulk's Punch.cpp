// Author: Gustavo Policarpo
// Name: Rulk's Punch
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2151

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
typedef pair < int, int > ii;
typedef pair < ii, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int M, N, X, Y;
int vis[101][101], mat[101][101];
int dx[]={-1, -1, -1, 0, 0, 0, 1, 1, 1},
	dy[]={-1, 0, 1, -1, 0, 1, -1, 0, 1};
	
bool dentro(int x, int y)
{
	return x>=0 && y>=0 && x<M && y<N;
}
void bfs(int x, int y, int c)
{
	queue <iii> q;
	vis[x][y]=1; mat[x][y]+=c;
	q.push(mp(mp(x, y), c-1));
	while(!q.empty()){
		x=q.front().F.F, y=q.front().F.S, c=q.front().S; q.pop();
		rep(i, 0, 9){
			int ax=x+dx[i], ay=y+dy[i];
			if(!dentro(ax, ay) || vis[ax][ay]) continue;
			vis[ax][ay]=1; mat[ax][ay]+=c;
			if(c==1) q.push(mp(mp(ax, ay), c));
			else q.push(mp(mp(ax, ay), c-1));
			
		}
	}
}
int main()
{
	int C, z=1; cin >> C;
	while(C--){
		scanf("%d %d %d %d", &M, &N, &X, &Y);
		rep(i, 0, M)
			rep(j, 0, N)
				scanf("%d", &mat[i][j]), vis[i][j]=0;
		bfs(X-1, Y-1, 10);
		printf("Parede %d:\n", z++);
		bool mark;
		rep(i, 0, M){
			mark=false;
			rep(j, 0, N){
				if(mark) printf(" ");
				else mark=true;
				printf("%d", mat[i][j]);
			}	
			printf("\n");
		}
	}

return 0;
}


