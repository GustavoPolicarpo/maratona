// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Escada do DINF
// Nível: 1
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2518

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
