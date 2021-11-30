// Author: Gustavo Policarpo
// Name: HameKameKa
// Level: 1
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2591

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED



int main()
{
	
	int n; scanf("%d ", &n);
	
	while(n--){
		
		char s[202]; scanf("%s", s);
		
		int a=0, b=0, i=1;
		
		while(s[i++]=='a') a++;
		while(s[i]!='a') i++;
		while(s[i++]=='a') b++;
		
		printf("k");
		for( i=0; i<a*b; i++ ) printf("a");
		printf("\n");
		
	}
	
}
