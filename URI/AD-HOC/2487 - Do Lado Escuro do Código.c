// Author: Gustavo Policarpo
// Name: Do Lado Escuro do Código
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2487

#include <stdio.h>

int main()
{
	long long int T;
	int A, N;
	while(scanf("%lld %d", &T, &A) !=EOF){
		
		long long int sum=0, i=0, um=1;
		while( (um << i) < T ) i++;
		while( (um << i) + A-1 > T ) i--;
		
		long long int out[A];
		int p=0;
		out[p++]=(um << i);
		
		sum+=(um<<i);
		A--;
		while(A){
			while(sum + (um<<i) + A-1 > T) i--;
			sum+=(um<<i);
			out[p++]=(um << i);
			A--;
		}
		out[0]+=(T-sum);
		
		for( i=0; i<p; i++ ){
			if(i) printf(" ");
			printf("%lld", out[i]);
		}
		printf("\n");
		
	}
	
	return 0;
		
}
