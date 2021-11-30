// Author: Gustavo Policarpo
// Name: O Mar não está para Peixe
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2393

#include <stdio.h>


int n, mat[101][101];

int main()
{
	
	scanf("%d", &n);
	int a, b, c, d, i, j;
	while(n--){
		scanf("%d %d %d %d", &a, &b, &c, &d);
		for( i=a; i<b; i++ )
		for( j=c; j<d; j++ )
		mat[i][j]=1;
	}
	
	int ans=0;
	for( i=0; i<101; i++ )
	for( j=0; j<101; j++ )
		if(mat[i][j]) ans++;
		
	printf("%d\n", ans);
	
	return 0;
		
}
