// Author: Gustavo Policarpo
// Name: Feira de Bactérias
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2340

#include <stdio.h>
#include <math.h>

int main()
{
	
	int n; scanf("%d", &n);
	int d, c, ans=0, i;
	double maior=0.0;
	for( i=0; i<n; i++ ){
		scanf("%d %d", &d, &c);
		double aux = (log(d))*c;
		if(aux>maior){
			maior=aux;
			ans=i;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
		
}
