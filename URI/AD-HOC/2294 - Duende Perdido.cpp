// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Duende Perdido
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2294

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


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int mat[20][20], vis[20][20], N, M, 
	dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

bool dentro(int x, int y){
	return x>=0 && x<N && y>=0 && y<M && mat[x][y]!=2 && vis[x][y]==0;
}
int solve(int x, int y, int t){
	
	queue <iii> q;
	q.push(mp(t, mp(x, y))); vis[x][y]=1;
	
	while(!q.empty()){
		x=q.front().S.F, y=q.front().S.S, t=q.front().F; q.pop();
		//cout << x << " " << y << endl;
		if(mat[x][y]==0) return t;
		
		rep(i, 0, 4){
			int ax=x+dx[i], ay=y+dy[i];
			if(!dentro(ax, ay)) continue;
			vis[ax][ay]=1;
			q.push(mp(t+1, mp(ax, ay)));
		}
	}
}
int main()
{
	scanf("%d %d", &N, &M);
	int x, y;
	rep(i, 0, N)
	rep(j, 0, M){
		scanf("%d", &mat[i][j]);
		if(mat[i][j]==3){
			x=i, y=j;
		}
	}
	
	printf("%d\n", solve(x, y, 0));
	



return 0;
}



