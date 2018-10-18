// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Arredondamento por Valor ...
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1305

#include <bits/stdc++.h>
using namespace std;

#define error 1e-10

int main()
{
	double num, cut;
	while(scanf("%lf %lf", &num, &cut) !=EOF){
		int aux=num;
		num-=aux;
		if(num-cut>error) aux++;
		printf("%d\n", aux);	
	}
return 0;
}
