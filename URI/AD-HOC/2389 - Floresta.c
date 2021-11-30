// Author: Gustavo Policarpo
// Name: Floresta
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2389

#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	int ans=0, l=2, r, ini, fim;
	
	while(1){
		if(l*l + (l-1)*(l-1) > n) break;
		ini=l, fim=n;
		
		while(ini<=fim){
			r=(ini+fim)/2;
			long long go=l;
			long long aux = go*r + (go-1)*(r-1);
			if(aux == n){
				ans++;
				break;
			}else if(aux > n){
				fim=r-1;
			}else{
				ini=r+1;
			}
		}
		l++;
	}
	
	printf("%d\n", ans);
	
	return 0;
		
}
