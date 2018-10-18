// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Entendendo o Sorobov
// Nível: 4
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2111

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int mat[7][9];

void build(int n, int j)
{
	if(n==0)
		mat[0][j]=1, mat[1][j]=0, mat[2][j]=0, 
		mat[3][j]=1, mat[4][j]=1, mat[5][j]=1, mat[6][j]=1;
	else if (n==1)
		mat[0][j]=1, mat[1][j]=0, mat[2][j]=1, 
		mat[3][j]=0, mat[4][j]=1, mat[5][j]=1, mat[6][j]=1;
	else if (n==2)
		mat[0][j]=1, mat[1][j]=0, mat[2][j]=1, 
		mat[3][j]=1, mat[4][j]=0, mat[5][j]=1, mat[6][j]=1;
	else if (n==3)
		mat[0][j]=1, mat[1][j]=0, mat[2][j]=1, 
		mat[3][j]=1, mat[4][j]=1, mat[5][j]=0, mat[6][j]=1;
	else if (n==4)
		mat[0][j]=1, mat[1][j]=0, mat[2][j]=1, 
		mat[3][j]=1, mat[4][j]=1, mat[5][j]=1, mat[6][j]=0;
	else if (n==5)
		mat[0][j]=0, mat[1][j]=1, mat[2][j]=0, 
		mat[3][j]=1, mat[4][j]=1, mat[5][j]=1, mat[6][j]=1;
	else if (n==6)
		mat[0][j]=0, mat[1][j]=1, mat[2][j]=1, 
		mat[3][j]=0, mat[4][j]=1, mat[5][j]=1, mat[6][j]=1;
	else if (n==7)
		mat[0][j]=0, mat[1][j]=1, mat[2][j]=1, 
		mat[3][j]=1, mat[4][j]=0, mat[5][j]=1, mat[6][j]=1;
	else if (n==8)
		mat[0][j]=0, mat[1][j]=1, mat[2][j]=1, 
		mat[3][j]=1, mat[4][j]=1, mat[5][j]=0, mat[6][j]=1;
	else if (n==9)
		mat[0][j]=0, mat[1][j]=1, mat[2][j]=1, 
		mat[3][j]=1, mat[4][j]=1, mat[5][j]=1, mat[6][j]=0;
	
	
}
int main()
{	

	int N; 
	while(scanf("%d", &N) !=EOF){
		
		int j=0;
		for(int i=100000000; i>=1; i/=10){
			build(N/i, j++), N%=i;
		}
			
			
		rep(i, 0, 2){
			rep(j, 0, 9)
				printf("%d", mat[i][j]);
			printf("\n");
		}
		printf("---------\n");
		rep(i, 2, 7){
			rep(j, 0, 9)
				printf("%d", mat[i][j]);
			printf("\n");
		}
		printf("\n");
	}

return 0;
}
