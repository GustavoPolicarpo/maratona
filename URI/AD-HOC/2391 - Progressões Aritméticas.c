// Author: Gustavo Policarpo
// Name: Progressões Aritméticas
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2391

#include <stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
	
	if(n==1){
		puts("1");
		return 0;
	}
	
	int v[n+2], i;
	for( i=0; i<n; i++ ) scanf("%d", &v[i]);
	
	int ans=1, r=v[1]-v[0];
	for( i=2; i<n; i++){
		if(v[i]-v[i-1]==r) continue;
		ans++;
		r=v[i+1]-v[i];
		i++;
	}
	
	printf("%d\n", ans);
	
	return 0;
		
}
