// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pirâmide da Sorte
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1946

#include <stdio.h>

double pb[5005][5005];

double solve(int S){
	
	int i, j;
	pb[0][0]=1.0;
	for(i=1; i<=S; i++){
		pb[i][0]=pb[i][i]=pb[i-1][0]/2.0;
		for(j=1; j<i; j++){
			pb[i][j]=pb[i-1][j-1]/2.0 + pb[i-1][j]/2.0;
		}
	}
	
	return pb[S][(S+1)/2]*100.0;
}

int main()
{
    
	int S; scanf("%d", &S);
	printf("%.2lf\n", solve(S-1));
	
	return 0;
		
}
