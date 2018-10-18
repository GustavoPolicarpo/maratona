// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Medianas
// Nível: 6
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1296

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


int main()
{
	double m1, m2, m3, sm, raiz, area;
	while(scanf("%lf %lf %lf", &m1, &m2, &m3) !=EOF){
		sm=0.5*(m1+m2+m3);
		raiz=sm*(sm-m1)*(sm-m2)*(sm-m3);
		if(raiz<error){
			printf("%.3lf\n", -1.0);
			continue;
		} 
		area=4.0/3.0*sqrt(raiz);
		printf("%.3lf\n", area);		
	}
		
return 0;
}
