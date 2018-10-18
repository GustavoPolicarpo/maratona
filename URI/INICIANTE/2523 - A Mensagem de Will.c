// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Mensagem de Will
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2523

#include <stdio.h>
#include <stdlib.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED


int main()
{
	
	char s[30];
	while(scanf("%s", s) !=EOF){
		int n; scanf("%d", &n);
		char ans[n+2]; int aux, i;
	
		for( i=0; i<n; i++ ){
			scanf("%d", &aux);
			ans[i]=s[aux-1];
		}	ans[n]='\0';
		
		printf("%s\n", ans);
		getchar();
		
	}
}
