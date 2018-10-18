// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sete
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2590

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define gc getchar
#define pc(x) putchar(x);

//LIFE IS NOT A PROBLEM TO BE SOLVED


int scanint()
{
    register int ccc = gc(); int x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    return x;
}

int main()
{
	
	int T, n, ans[4]={1, 7, 9, 3};
	
	T=scanint();
	while(T--){
		
		n=scanint()%4;
		printf("%d\n", ans[n]);
		
	}
	
}
