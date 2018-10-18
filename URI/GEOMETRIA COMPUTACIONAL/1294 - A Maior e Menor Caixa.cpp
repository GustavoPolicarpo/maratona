// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Maior e Menor Caixa
// Nível: 5
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1294

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


int main()
{
	double L, W, A, B, C, x1, x2, delta;
	while(scanf("%lf %lf", &L, &W) !=EOF){
		A=12.0, B=4.0*L+4.0*W, C=L*W;
		delta=B*B-4.0*A*C;
		x1=(B-sqrt(delta))/(2.0*A);
		x2=min(L, W)/2.0;
		printf("%.3lf %.3lf %.3lf\n", x1, 0.0, x2);
	}

return 0;
}
