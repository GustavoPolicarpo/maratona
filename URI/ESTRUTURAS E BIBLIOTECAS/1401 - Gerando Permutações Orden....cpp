// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Gerando Permutações Orden...
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1401

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
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, string > ii;
typedef pair < double, int > iii;


int main()
{
	int T; cin >> T; char n[10];
	while(T--){
		scanf("%s", &n);
		int tam=strlen(n);
		sort(n, n+tam);
		do{
			rep(i, 0, tam)
				printf("%c", n[i]);
			printf("\n");
		} while(next_permutation(n, n+tam));
		printf("\n");
	}
	
	
return 0;
}
