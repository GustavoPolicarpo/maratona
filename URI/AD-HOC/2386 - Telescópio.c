// Author: Gustavo Policarpo
// Name: Telescópio
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2386

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
