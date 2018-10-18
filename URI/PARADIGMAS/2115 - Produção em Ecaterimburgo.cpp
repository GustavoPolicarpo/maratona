// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Produção em Ecaterimburgo
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2115

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int n;
ii v[100010];

int main(){

	while(scanf("%d", &n)!=EOF){
		rep(i, 0, n) scanf("%d %d", &v[i].F, &v[i].S);
		sort(v, v+n);
		int ta = 0;
		rep(i, 0, n)
			ta = max(v[i].F, ta)+v[i].S;
		printf("%d\n", ta);
	}
	
	return 0;
} 
