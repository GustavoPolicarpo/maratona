// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Maçãs
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1517

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F

typedef pair < int, int > ii;
typedef long long int ll;

int dx[]={-1,0,0,1,-1,-1,1,1}, dy[]={0,-1,1,0,-1,1,-1,1};
int cai[21][21][2001], pd[21][21][2001];
int N, M, K, lt;

bool dentro(int x, int y)
{
	return x>=1 && y>=1 && x<=N && y<=M;
}
int solve(int x, int y, int k)
{
	if(k==lt+1) return 0;
	if(pd[x][y][k]!=-1) return pd[x][y][k];
	int ret=solve(x, y, k+1)+cai[x][y][k];
	rep(i, 0, 8){
		int ax=x+dx[i], ay=y+dy[i];
		if(!dentro(ax, ay)) continue;
		ret=max(ret,solve(ax, ay, k+1)+cai[x][y][k]);
	}
	return pd[x][y][k]=ret;
}

int main ()
{
	while(scanf("%d %d %d", &N, &M, &K) and N+M+K){
		memset(pd, -1, sizeof pd), memset(cai, 0, sizeof cai);
		int x, y, t; lt=0;
		rep(i, 0, K){
			scanf("%d %d %d", &x, &y, &t);
			cai[x][y][t]=1;
			if(t>lt) lt=t;
		}
		scanf("%d %d", &x, &y);
		int out=solve(x, y, 0);
		printf("%d\n", out);
	}
	 
return 0;
}
