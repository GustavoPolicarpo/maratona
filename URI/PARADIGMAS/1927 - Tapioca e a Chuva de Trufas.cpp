// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tapioca e a Chuva de Trufas
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1927

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
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, fim=0, cai[21][21][1001], pd[21][21][1001];
int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

bool dentro(int x, int y)
{
	return x>=0 && y>=0 && x<=20 && y<=20;
}
int solve(int x, int y, int t)
{
	if(t>fim) return 0;
	if(pd[x][y][t]!=-1) return pd[x][y][t];
	
	int ret=solve(x, y, t+1)+cai[x][y][t];
	rep(i, 0, 4){
		int ax=x+dx[i], ay=y+dy[i];
		if(!dentro(ax, ay)) continue;
		ret=max(ret, solve(ax, ay, t+1)+cai[x][y][t]);
	}
	
	return pd[x][y][t]=ret;
}
int main()
{		
	int a, b, c;
	memset(cai, 0, sizeof cai);
	memset(pd, -1, sizeof pd);
	scanf("%d", &N);
	rep(i, 0, N){
		scanf("%d %d %d", &a, &b, &c);
		cai[a][b][c]++;
		if(c>fim) fim=c;
	}
	int out=solve(6, 6, 0);
	printf("%d\n", out);

return 0;
}
