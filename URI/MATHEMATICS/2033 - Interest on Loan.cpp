// Author: Gustavo Policarpo
// Name: Interest on Loan
// Level: 6
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2033

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F3
#define MAXV 100001

#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}


int main()
{
	long double C, i;
	int n;
	while(scanf("%llf", &C) !=EOF){
		scanf("%llf %d", &i, &n);
		long double s=(C*i*n);
		long double c=C*powl(1+i, n); c-=C;
		long double dif=fabs(c-s);
		printf("DIFERENCA DE VALOR = %.2Lf\n", dif);
		printf("JUROS SIMPLES = %.2Lf\n", s);
		printf("JUROS COMPOSTO = %.2Lf\n", c);
	}
	
	
	return 0;	
}
