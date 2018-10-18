// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Telescópio
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2386

#include <stdio.h>

int main()
{
	
	int t; scanf("%d", &t);
	int n; scanf("%d", &n);
	
	int ans=0, aux;
	while(n--){
		scanf("%d", &aux);
		if(aux*t >= 40000000) ans++;
	}
	
	printf("%d\n", ans);
	
	return 0;
		
}
