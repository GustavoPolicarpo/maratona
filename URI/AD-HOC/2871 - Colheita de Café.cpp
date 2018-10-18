// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Colheita de Café
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2871

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;



int main(){
	
	int N, M;
	while(cin >> N >> M){
		int tt = 0, aux;
		rep(i, 0, N) rep(j, 0, M){
			cin >> aux;
			tt+=aux;
		}
		printf("%d saca(s) e %d litro(s)\n", tt/60, tt%60);
	}
	
	return 0;
} 
