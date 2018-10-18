// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Juros do Projeto
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2170

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


int main()
{
	double X, Y, P; int z=1;
	while(scanf("%lf %lf", &X, &Y) !=EOF){
		P=(Y-X)/X*100;
		printf("Projeto %d:\n", z++);
		printf("Percentual dos juros da aplicacao: %.2lf %\n\n", P);
		
	}

return 0;
}


