// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Remendo
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1475

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

int N, fim, C, T1, T2, n[2001], pd[2001];

int solve(int i)
{
	if(i>=fim) return 0;
	if(pd[i]!=-1) return pd[i];
	int ret=0;
	int aux=n[i]+T1;
	int x=i+1;
	while(aux>=n[x]) x++;
	aux=n[i]+T2;
	int y=i+1;
	while(aux>=n[y]) y++;
	ret=min(solve(x)+T1, solve(y)+T2);
	return pd[i]=ret;
}
int main ()
{
	while(scanf("%d %d %d %d", &N, &C, &T1, &T2) !=EOF){
		rep(i, 0, N){
			scanf("%d", &n[i]);
			pd[i]=-1, pd[i+N]=-1;
		}
		rep(i, N, N+N)
			n[i]=n[N-1]+n[i-N];

		fim=N;
		int out=solve(0);
		
		printf("%d\n", out);
			
	}
		
return 0;
}
