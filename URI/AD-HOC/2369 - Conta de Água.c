// Author: Gustavo Policarpo
// Name: Conta de Água
// Level: 1
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2369

#include <stdio.h>

int main()
{
	
	int n; scanf("%d", &n);
	int ans=0;
	if(n<=10) printf("%d\n", 7);
	else if(n<=30) printf("%d\n", 7+n-10);
	else if(n<=100) printf("%d\n", 7+20+(n-30)*2);
	else printf("%d\n", 7+20+140+(n-100)*5);
	
	return 0;
		
}
