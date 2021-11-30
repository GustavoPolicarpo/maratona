// Author: Gustavo Policarpo
// Name: Constructible Regular Pol...
// Level: 6
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1577

#include <stdio.h>

#define MAX 1010
int fermat[]={3, 5, 17, 257, 65537}, qt=5;

int main()
{
	
	int T; scanf("%d", &T);
	
	while(T--){
		int n; scanf("%d", &n);
		while(n%2==0) n/=2;
		
		int yep=1, i;
		for(i=0; i<qt; i++){
			if(n==1) break;
			if(n%fermat[i]!=0){
				continue;
			}
			n/=fermat[i];
			if(n==1) break;
			if(n%fermat[i]==0){
				yep=0;
				break;
			}
		}
		
		if(n!=1) yep=0;
		
		yep ? puts("Yes") : puts("No");
		
	}
	
	
	return 0;
		
}
