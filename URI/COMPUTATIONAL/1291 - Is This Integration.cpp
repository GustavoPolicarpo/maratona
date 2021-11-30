// Author: Gustavo Policarpo
// Name: Is This Integration?
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1291

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
	
	double a;
	while(scanf("%lf", &a) !=EOF)	{
		double at, r1, r2, r3, aux;
		at=a*a;
		
		r1=2.0*(at/2.0-a*a*sqrt(3.0)/8.0-a*a/2.0*(M_PI/6.0));
		
		r2=at-M_PI*a*a/4.0-2.0*r1;
		
		r3=at-4.0*r1-4.0*r2;
		
		printf("%.3lf %.3lf %.3lf\n", r3, 4.0*r2, 4.0*r1);
				
	}
	
return 0;
}
