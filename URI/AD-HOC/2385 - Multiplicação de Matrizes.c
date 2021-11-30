// Author: Gustavo Policarpo
// Name: Multiplicação de Matrizes
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2385

#include <stdio.h>

int main()
{
	
	int n, p, q, r, s, x, y, i, ax, ay;
	scanf("%d", &n);
	scanf("%d%d%d%d%d%d", &p,&q,&r,&s,&x,&y);
	scanf("%d%d", &ax,&ay);
	
	long long int ans=0, aa, bb;
	for (i=1; i<=n; i++){
		aa=(p*ax + q*i)%x;
		bb=(r*i + s*ay)%y;
		ans+=aa*bb;
	}
	
	printf("%lld\n", ans);
	
	return 0;
		
}
