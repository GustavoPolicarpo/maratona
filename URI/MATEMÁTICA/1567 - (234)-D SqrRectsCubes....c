// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: (2/3/4)-D Sqr/Rects/Cubes...
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1567

#include <stdio.h>

int main()
{
	long long n;
	while(scanf("%lld", &n) !=EOF){
	    
		long long s1, s2, r2, s3, r3, s4, r4;
		s1 = n*(n+1)/2;
		s2 = s1*(2*n+1)/3;
		s3 = s1*s1;
		s4 = s2*(3*n*n+3*n-1)/5;
		r2 = s3-s2;
		r3 = s3*s1-s3;
		r4 = s3*s3-s4;
		
		printf("%lld %lld %lld %lld %lld %lld\n", s2, r2, s3, r3, s4, r4);
		
	}
	
	return 0;
		
}
