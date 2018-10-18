// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Contando Ciclos
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2497

#include <stdio.h>
#include <stdlib.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED


int main()
{
	
	int n, z=1;
	while(scanf("%d", &n) && (n!=-1)){
		printf("Experiment %d: %d full cycle(s)\n", z++, n/2);
	}
	
}
