// Author: Gustavo Policarpo
// Name: Running
// Level: 3
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2516

#include <stdio.h>
#include <stdlib.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED


int main()
{
	
	double a, b, c;
	while(scanf("%lf%lf%lf", &a, &b, &c) !=EOF){
		
		if(b<=c){
			puts("impossivel");
			continue;
		}
		
		double tempo=a/(b-c);
		printf("%.2lf\n", tempo);
		
	}
	
}
