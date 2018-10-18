// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Feira de Bactérias
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2340

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
