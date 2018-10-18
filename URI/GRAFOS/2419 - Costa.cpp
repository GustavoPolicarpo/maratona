// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Costa
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2419

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

int mat[1010][1010], N, M, ans, vis[1010][1010];
int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

bool dentro(int x, int y){
	return x>=0 && y>=0 && x<=N+1 && y<=M+1 && !vis[x][y];
}

void bfs(int x, int y){
	queue <ii> q;
	q.push(mp(x, y)); vis[x][y]=1;
	
	while(!q.empty()){
		x=q.front().F, y=q.front().S; q.pop();
		
		rep(i, 0, 4){
			int ax=x+dx[i], ay=y+dy[i];
			if(!dentro(ax, ay)) continue;
			vis[ax][ay]=1;
			if(mat[ax][ay]==1) ans++, vis[ax][ay]=2;
			else q.push(mp(ax, ay));
		}
	}
	return;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	scanf("%d %d", &N, &M);
	
	char in;
	rep(i, 0, N)
	rep(j, 0, M){
		scanf(" %c", &in);
		if(in=='.') mat[i+1][j+1]=0;
		else mat[i+1][j+1]=1;
	}
	
	ans=0;
	bfs(0, 0);
	rep(i, 0, N+2)
	rep(j, 0, N+2)
	if(!vis[i][j]&&!mat[i][j])
		bfs(i, j);
	
	printf("%d\n", ans);

	return 0;
	
}
