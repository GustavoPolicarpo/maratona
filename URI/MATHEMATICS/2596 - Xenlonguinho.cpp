// Author: Gustavo Policarpo
// Name: Xenlonguinho
// Level: 2
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2596

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


int main(){
	
	int C=scanint();
	while(C--){
		int N=scanint(), ans=N, aux=1;
		
		while(aux*aux<=N) ans--, aux++;
		
		printf("%d\n", ans);
		
	}
}
