// Author: Gustavo Policarpo
// Name: Notas da Prova
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2344

#include <stdio.h>

int main()
{
	
	int n;
	scanf("%d", &n);
	
	if(n== 0) puts("E");
	else if(n<=35) puts("D");
	else if(n<=60) puts("C");
	else if(n<=85) puts("B");
	else if(n<=100) puts("A");
	
	return 0;
		
}
