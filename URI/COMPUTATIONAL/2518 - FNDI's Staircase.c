// Author: Gustavo Policarpo
// Name: FNDI's Staircase
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2518

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED


int main()
{
	
	double n, h, c, l;
	
	while(scanf("%lf %lf %lf %lf", &n, &h, &c, &l) !=EOF){
		h/=100.0, c/=100.0, l/=100.0;
		
		double comp=n*c, alt=n*h, hip=sqrt(comp*comp + alt*alt), ans=l*hip;
		
		printf("%.4lf\n", ans);
		
		
	}
}
