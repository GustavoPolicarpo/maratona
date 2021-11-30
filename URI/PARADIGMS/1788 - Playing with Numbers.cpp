// Author: Gustavo Policarpo
// Name: Playing with Numbers
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1788

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F
#define limite 10000005

typedef pair < int, int > ii;
typedef long long int ll;

int pd[1001][1001][6], mat[1001][1001];
int L, C, K;
int dx[]={-1,0,1,0}, dy[]={0,1,0,-1}, op; char o;

int ehprimo[limite];
void crivo()
{
	rep(i, 2, limite)
		ehprimo[i]=1;
		
	ehprimo[0]=ehprimo[1]=0;
	
	for(ll i=2; i<=limite; i++)
		if(ehprimo[i]==1){
			for(ll j=i*i; j<=limite; j+=i)
				ehprimo[j]=0;
		}
}

bool dentro(int x, int y)
{
	return x>=0 && y>=0 && x<L && y<C;
}
int solve(int x, int y, int k)
{
	if(pd[x][y][k]!=-1) return pd[x][y][k];
	int ret=0;
	rep(i, op, op+2){
		int ax=x+dx[i], ay=y+dy[i];
		if(!dentro(ax, ay)) continue;
		if(mat[ax][ay]<mat[x][y])
			ret=max(ret, solve(ax, ay, k)+1);
		
		else if(k>0 && ehprimo[mat[x][y]])
			ret=max(ret, solve(ax, ay, k-1)+1);
	}
	return pd[x][y][k]=ret;
}

int main ()
{
	crivo();
	while(scanf("%d %d %d", &L, &C, &K) and L+C+K){
		
		scanf(" %c", &o);
		rep(i, 0, L)
			rep(j, 0, C){
				scanf("%d", &mat[i][j]);
				rep(k, 0, K+1) pd[i][j][k]=-1;
			}
		
		if(o=='N') op=0;
		else op=2;
		
		int out=0;
		rep(i, 0, L)
			rep(j, 0, C)
				out=max(out,solve(i, j, K)+1);
		printf("%d\n", out);	
	}
		 
return 0;
}
