// Author: Gustavo Policarpo
// Name: Counting Cycles
// Level: 1
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2497

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
