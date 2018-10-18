// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Garçom
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2373

#include <stdio.h>

int main()
{
	int n; scanf("%d", &n);
	int ans=0, l, c;
	while(n--){
		scanf("%d %d", &l, &c);
		if(l>c) ans = ans+c;
	}
	printf("%d\n", ans);
	
	return 0;
		
}
