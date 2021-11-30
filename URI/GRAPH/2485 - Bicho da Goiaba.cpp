// Author: Gustavo Policarpo
// Name: Bicho da Goiaba
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2485

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


int dx[]={-1, -1, -1, 0, 0, 1, 1, 1},
	dy[]={-1, 0, 1, -1, 1, -1, 0, 1};
	
int N, M, mat[101][101], vis[101][101];

bool dentro(int x, int y){
	return x>=0 && y>=0 && x<N && y<M && mat[x][y] && vis[x][y]==0;
}

int bfs(int x, int y, int c){
	queue <iii> q;
	q.push(mp(0, mp(x, y)));
	int ret=0;
	while(!q.empty()){
		c=q.front().F, x=q.front().S.F, y=q.front().S.S; q.pop();
		
		rep(i, 0, 8){
			int ax=x+dx[i], ay=y+dy[i];
			if(!dentro(ax, ay)) continue;
			vis[ax][ay]=c+1;
			ret=vis[ax][ay];
			q.push(mp(c+1, mp(ax, ay)));
		}
	}
	
	return ret;
}

int main()
{
	int T; cin >> T;
	while(T--){
		scanf("%d %d", &N, &M);
		rep(i, 0, N)
		rep(j, 0, M){
			scanf("%d" ,&mat[i][j]);
			vis[i][j]=0;
		}
		int x, y;
		scanf("%d %d", &x, &y);
		x--, y--;
		vis[x][y]=-1;
		
		printf("%d\n", bfs(x, y, 0));
		
		
	}
	
	
	return 0;
	
}
