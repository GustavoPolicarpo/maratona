// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Transfira Para o Professor
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2563

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;

int N, K;
int peso[111], val[111], pd[111][10010];

int solve(int i, int k){
	if(i==N || k==0) return 0;
	if(pd[i][k]!=-1) return pd[i][k];
	
	int ret=solve(i+1, k);
	if(k>=peso[i]) ret=max(ret, solve(i+1, k-peso[i])+val[i]);
	
	return pd[i][k]=ret;
}
int main()
{
	
	while(scanf("%d %d", &N, &K)!=EOF){
		
		rep(i, 0, N+2) rep(j, 0, K+2) pd[i][j]=-1;
		
		rep(i, 0, N) scanf("%d", &val[i]);
		rep(i, 0, N) scanf("%d", &peso[i]);
		
		printf("%d\n", solve(0, K));
		
	}


	return 0;
	
}
