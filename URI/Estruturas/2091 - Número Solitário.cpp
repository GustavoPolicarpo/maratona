// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Número Solitário
// Nível: 5
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2091

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
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int N; ull A;

int main()
{
	ull in=0;
	while( scanf("%d", &N) && N ){
		in=0;
		while(N--){
			scanf("%llu", &A);
			in^=A;
		}
		printf("%lld\n", in);
	}
}
