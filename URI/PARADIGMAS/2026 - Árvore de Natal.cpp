// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Árvore de Natal
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2026

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
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int P;
int valor[100], peso[100], pd[100][1000];
int solve(int i, int c)
{
	if(i==P) return 0;
	if(pd[i][c]!=-1) return pd[i][c];
	int ret=solve(i+1, c);
	if(c-peso[i]>=0) ret=max(ret, solve(i+1, c-peso[i])+valor[i]);
	return pd[i][c]=ret;	
}

int main()
{	
	int N, W, z=1; cin >> N;
	while(N--){	
		scanf("%d %d", &P, &W);
		
		rep(i, 0, P){
			valor[i]=0, peso[i]=0;
			rep(j, 0, W+1)
				pd[i][j]=-1;
		}		
		rep(i, 0, P)
			scanf("%d %d", &valor[i], &peso[i]);
					
		int out=solve(0, W);
		printf("Galho %d:\nNumero total de enfeites: %d\n\n", z++, out);		
	}
		
return 0;
}
