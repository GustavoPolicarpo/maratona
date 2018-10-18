// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tabelas Hash
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1256

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


int main()
{
	int N; cin >> N; bool mark=false;
	while(N--){
		if(mark) printf("\n");
		else mark=true;
		int M, C, aux;
		cin >> M >> C;
		vector <int> m[M];
		rep(i, 0, C){
			scanf("%d", &aux);
			m[aux%M].pb(aux);
		}
		rep(i, 0, M){
			printf("%d", i);
			rep(j, 0, m[i].size())
				printf(" -> %d" , m[i][j]);
			printf(" -> \\\n");	
		}
	}
	
return 0;
}
