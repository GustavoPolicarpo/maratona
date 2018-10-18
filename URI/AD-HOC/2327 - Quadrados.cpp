// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Quadrados
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2327

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define MAXV 100001
#define mod 1000000007
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;




int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int N; cin >> N; int mat[N][N];
	
	rep(i, 0, N)
	rep(j, 0, N)
		cin >> mat[i][j];
	
	int sum=0;
	rep(i, 0, N) sum+=mat[i][0];
	
	rep(i, 0, N){
		int aux=0;
		rep(j, 0, N)
			aux+=mat[i][j];
		if(aux!=sum){
			printf("-1\n");
			return 0;
		}
	}
	
	rep(j, 0, N){
		int aux=0;
		rep(i, 0, N)
			aux+=mat[i][j];
		if(aux!=sum){
			printf("-1\n");
			return 0;
		}
	}
	
	int aux=0;
	rep(i, 0, N) aux+=mat[i][i];
	if(aux!=sum){
		printf("-1\n");
		return 0;
	}
	
	aux=0;
	rep(i, 0, N) aux+=mat[i][N-i-1];
	if(aux!=sum){
		printf("-1\n");
		return 0;
	}
	
	printf("%d\n", sum);
		
	return 0;
	
}
