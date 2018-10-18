// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Problema Fácil de Rujia Liu?
// Nível: 4
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1424

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
	int n, m;
	while(scanf("%d %d", &n, &m) !=EOF){
		map <ii, int> tab; map <int, int>last;
		int vet[n];
		rep(i, 0, n){
			scanf("%d", &vet[i]);
			if(last.count(vet[i])){
				last[vet[i]]++;
				tab[mp(last[vet[i]], vet[i])]=i+1;
			}	
			else{
				last[vet[i]]=1;
				tab[mp(1, vet[i])]=i+1;
			}	
		}
		int k, v;
		rep(i, 0, m){
			scanf("%d %d", &k, &v);
			if(tab.count(mp(k, v))){
				printf("%d\n", tab[mp(k, v)]);
			}
			else
				printf("%d\n", 0);
		}
	}
return 0;
}
