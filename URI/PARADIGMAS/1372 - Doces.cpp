// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Doces
// Nível: 6
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1372

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
#define error 1e-12

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int L, C, l[100001], c[100001], pd[100001];

int solveone(int i)
{
	if(i>=C) return 0;
	if(pd[i]!=-1) return pd[i];
	int ret=solveone(i+1);
	ret=max(ret, solveone(i+2)+c[i]);
	
	return pd[i]=ret;
}
int solvetwo(int i)
{
	if(i>=L) return 0;
	if(pd[i]!=-1) return pd[i];
	int ret=solvetwo(i+1);
	ret=max(ret, solvetwo(i+2)+l[i]);
	
	return pd[i]=ret;
}

int main()
{
	while(scanf("%d %d", &L, &C) and L+C){
		rep(i, 0, L){
			rep(j, 0, C){
				pd[j]=-1;
				scanf("%d", &c[j]);
			}
			l[i]=solveone(0);
		}
		rep(i, 0, L) pd[i]=-1;
		int out=solvetwo(0);
		printf("%d\n", out);
	}
	
	
return 0;
}


