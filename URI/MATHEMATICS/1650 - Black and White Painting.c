// Author: Gustavo Policarpo
// Name: Black and White Painting
// Level: 3
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1650

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
