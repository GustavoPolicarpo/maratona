// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pintura Preto e Branco
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1650

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

int main()
{
	int n, m, c;
	
	while(scanf("%d %d %d", &n, &m, &c) && n){
		printf("%d\n", ((n-7)*(m-7)+c)/2);
	}
	
}
