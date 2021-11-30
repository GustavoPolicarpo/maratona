// Author: Gustavo Policarpo
// Name: StopAll
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2959

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

const int MAX = 2e3+3;
const int mod = 1e9+7;

int n, m, p, mat[404][404];

int main(){
	
	scanf("%d %d %d", &n, &m, &p);
	int i, j, k, u, v;
	for(i=0; i<m; i++){
		scanf("%d %d", &u, &v); u--, v--;
		mat[u][v] = mat[v][u] = 1;
	}
	
	for(k=0; k<n; k++) for(i=0; i<n; i++) for(j=0; j<n; j++){
		mat[i][j] |= (mat[i][k]&mat[k][j]);
	}
	
	for(i=0; i<p; i++){
		scanf("%d %d", &u, &v); u--, v--;
		if(mat[u][v]) puts("Lets que lets");
		else puts("Deu ruim");
	}
	
	
		

    return  0;
}
