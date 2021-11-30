// Author: Gustavo Policarpo
// Name: Tiles
// Level: 4
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2246

#define gc getchar_unlocked
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

#define INF 0x3f3f3f3f
#define MAXV 100001
#define mod 1000000007
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int N, M, mat[202][202], vis[202][202];

int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

bool dentro(int x, int y){
	return x>=0 && y>=0 && x<N && y<M;
}

int dfs(int i, int j, int op){
	if(vis[i][j]) return 0;
	vis[i][j]=1;
	int ret=0;
	rep(k, 0, 4){
		int x=i+dx[k], y=j+dy[k];
		if(dentro(x, y) && mat[x][y]==op && !vis[x][y])
			ret+=dfs(x, y, op);
	}
	return ret+1;
}

int main()
{
	scanf("%d %d", &N, &M); int fim=0;
	rep(i, 0, N)
	rep(j, 0, M)
		scanf("%d", &mat[i][j]), fim=max(fim, mat[i][j]);
	
	int out=INF;
	rep(i, 0, N)
	rep(j, 0, M){
		if(vis[i][j])  continue;
		out=min(out, dfs(i, j, mat[i][j]));
	}
	
	printf("%d\n", out)	;
	
	
return 0;
}
