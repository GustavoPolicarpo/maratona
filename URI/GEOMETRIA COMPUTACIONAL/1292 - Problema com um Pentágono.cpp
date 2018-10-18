// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Problema com um Pentágono
// Nível: 4
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1292

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
	double  a=sin(81*M_PI/180), 
			b=sin(9*M_PI/180), 
			c=tan(27*M_PI/180);
			
	double l1, l2, l, F, aux;
	while(cin >> F){
		l1=a*F;
		aux=b*F;
		l2=c*aux;
		l=l1+l2;
		printf("%.10f\n", l);
	}
	
return 0;
}
