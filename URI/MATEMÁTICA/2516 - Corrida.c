// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Corrida
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2516

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
