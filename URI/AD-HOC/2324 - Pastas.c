// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pastas
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2324

#include <stdio.h>

int main()
{
	
	int n, p;
	
	scanf("%d %d", &p, &n);
	
	int qt[p+2];
	memset(qt, 0, sizeof qt);
	
	int u;
	while(n--){
		scanf("%d", &u);
		qt[u]++;
	}
	
	int i, yep=1, tt=qt[1];
	for( i=2; i<=p; i++ ){
		if(qt[i]>qt[i-1] || qt[i]<tt-1){
			yep=0;
			break;
		}
	}
	
	yep ? puts("S") : puts("N");
	
	return 0;
		
}
