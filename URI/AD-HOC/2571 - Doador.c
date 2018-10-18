// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Doador
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2571

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED


int main()
{
	
	double M, p, j, x;
	scanf("%lf %lf %lf %lf", &M, &p, &j, &x);
	
	x=x*100.0/j/M;
	
	int n = log(x)/log(1.0-p/100.0);
	
	if(n<0) n=0;
	printf("%d\n", n);
	
	return 0;
	
}
