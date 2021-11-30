// Author: Gustavo Policarpo
// Name: Garçom
// Level: 1
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2373

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
