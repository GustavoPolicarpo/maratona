// Author: Gustavo Policarpo
// Name: The Last Analógimôn
// Level: 5
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2520

#include <stdio.h>
#include <stdlib.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED


int main()
{
	
	int n, m;
	while(scanf("%d %d", &n, &m) !=EOF){
		int xa, ya, xb, yb, mat[n][m], ans=0, i, j;
		
		for( i=0; i<n; i++ ){
			for( j=0; j<m; j++ ){
				scanf("%d", &mat[i][j]);
				if(mat[i][j]==1) xa=i, ya=j;
				else if(mat[i][j]==2) xb=i, yb=j;
			}
		}
		
		ans=abs(xa-xb)+abs(ya-yb);
		printf("%d\n", ans);
		
	}
}
