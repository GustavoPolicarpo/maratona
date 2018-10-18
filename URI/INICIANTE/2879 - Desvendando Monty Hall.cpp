// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Desvendando Monty Hall
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2879

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
	
	
	int N; scanf("%d", &N); int aux, ans = 0;
	rep(i, 0, N){
		scanf("%d", &aux);
		ans += aux!=1;
	}
	printf("%d\n", ans);
	
	return 0;
} 
