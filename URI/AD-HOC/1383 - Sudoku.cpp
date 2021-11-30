// Author: Gustavo Policarpo
// Name: Sudoku
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1383

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define error 1e-8

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int mat[9][9];
void verif(int z)
{
	printf("Instancia %d\n", z);
	rep(i, 0, 9){
		set <int> aux;
		rep(j, 0, 9)
			aux.insert(mat[i][j]);
		if(aux.size()!=9){
			printf("NAO\n");
			return;
		}
	}
	rep(j, 0, 9){
		set <int> aux;
		rep(i, 0, 9)
			aux.insert(mat[i][j]);
		if(aux.size()!=9){
			printf("NAO\n");
			return;
		}
	}
	int di[]={0, 0, 0, 3, 3, 3, 6, 6, 6};
	int dj[]={0, 3, 6, 0, 3, 6, 0, 3, 6};
	
	rep(k, 0, 9){
		set <int> aux;
		rep(i, di[k], di[k]+3)	
			rep(j, dj[k], dj[k]+3)
				aux.insert(mat[i][j]);
		if(aux.size()!=9){
			printf("NAO\n");
			return;
		}		
	}
	printf("SIM\n")	;
}

int main()
{
	int N; cin >> N;
	rep(z, 1, N+1){	
		rep(i, 0, 9)
			rep(j, 0, 9)
				scanf("%d", &mat[i][j]);
		verif(z);
		printf("\n");
	}
	
return 0;
}
