// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cortando Canos
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1798

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

int N, T, pd[1001][5001], tam[1001], val[1001]; 

int solve(int i, int c)
{
	if(i==N) return 0;
	if(pd[i][c]!=-1) return pd[i][c];
	int ret=solve(i+1, c);
	if(c-tam[i]>=0)
		ret=max(ret, max(solve(i+1, c-tam[i])+val[i], solve(i, c-tam[i])+val[i]));
		
	return pd[i][c]=ret;
}
int main ()
{
	scanf("%d %d", &N, &T);
	
	rep(i, 0, N){
		scanf("%d %d", &tam[i], &val[i]);
	}
	memset(pd, -1, sizeof pd);
	
	int out=solve(0, T);
	printf("%d\n", out);
	
return 0;
}
