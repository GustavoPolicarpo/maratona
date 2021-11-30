// Author: Gustavo Policarpo
// Name: Cracker
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2515

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

int min(int a, int b){
	if(a<=b) return a;
	return b;
}

int main()
{
	int n;
	while(scanf("%d", &n) !=EOF){
		int vet[n], sum=0, i, ans=0, sa=0;
		
		for( i=0; i<n; i++ ){
			scanf("%d", &vet[i]);
			sum+=vet[i];
		}
		
		sa=vet[0];
		for( i=1; i<n; i++ ){
			if(min(sa, sum-sa) > ans){
				ans=min(sa, sum-sa);
			}
			sa+=vet[i];
		}
		
		printf("%d %d\n", ans, sum-ans);
		
	}
	
}
