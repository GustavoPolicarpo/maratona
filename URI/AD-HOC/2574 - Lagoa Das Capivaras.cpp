// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Lagoa Das Capivaras
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2574

#include <bits/stdc++.h>
#define rep(i, a, b) for(int i=a; i<b; i++)

using namespace std;
//LIFE IS NOT A PROBLEM TO BE SOLVED

int N, G;
int mat[2050][2050], sum[2050][2050];

int main()
{
	
	scanf("%d %d", &N, &G);
	
	rep(i, 0, N) rep(j, 0, N) scanf("%d", &mat[i][j]);
	
	sum[0][0]=mat[0][0];
	rep(i, 1, N) 
		sum[i][0]=sum[i-1][0]+mat[i][0],
		sum[0][i]=sum[0][i-1]+mat[0][i];
	rep(i, 1, N)
	rep(j, 1, N)
		sum[i][j]=sum[i-1][j]+sum[i][j-1]+mat[i][j]-sum[i-1][j-1];
	
	int ans=0;
	for(int z=1; z<=N; z*=2){
		int yep=1;
		for(int i=0; i<N; i+=z){
			for(int j=0; j<N; j+=z){
				int val=sum[i+z-1][j+z-1];
				if(i) val-=sum[i-1][j+z-1];
				if(j) val-=sum[i+z-1][j-1];
				if(i && j) val+=sum[i-1][j-1];
				if(val<G){
					yep=0;
					break;
				}
			}
			if(!yep) break;
		}
		if(yep){
			ans=N*N/z/z;
			break;
		}
	}	
	
	printf("%d\n", ans);
	
	return 0;
	
}
