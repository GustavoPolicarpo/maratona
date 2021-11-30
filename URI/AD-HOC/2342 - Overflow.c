// Author: Gustavo Policarpo
// Name: Overflow
// Level: 1
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2342

#include <stdio.h>

int main()
{
	
	int n;
	scanf("%d", &n);
	
	int p, q; char op;
	scanf("%d %c %d", &p, &op, &q);
	
	if(op=='+'){
		if(p+q <= n) puts("OK");
		else puts("OVERFLOW");
	}else{
		if(p*q <= n) puts("OK");
		else puts("OVERFLOW");
	}
	
	return 0;
		
}
