// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ele Está Impedido!
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1410

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
#define error 1e-8

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;




int main()
{
	int A, D, aux, ma, md1, md2;
	while(scanf("%d %d", &A, &D) and A+D){
		ma=INF, md1=INF, md2=INF;
		rep(i, 0, A){
			scanf("%d", &aux);
			if(aux<ma)
				ma=aux;
		}
		rep(i, 0, D){
			scanf("%d", &aux);
			if(aux<=md1)
				md2=md1, md1=aux;
			else if(aux<md2)
				md2=aux;		
		}
		if(ma>=md2) printf("N\n");
		else printf("Y\n");
	}
	
return 0;
}
