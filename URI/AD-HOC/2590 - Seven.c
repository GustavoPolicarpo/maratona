// Author: Gustavo Policarpo
// Name: Seven
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2590

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED



int main()
{
	
	int T, n, ans[4]={1, 7, 9, 3}; 
	
	scanf("%d ", &T);
	while(T--){
		
		scanf("%d", &n);
		printf("%d\n", ans[n%4]);
		
	}
	
}


