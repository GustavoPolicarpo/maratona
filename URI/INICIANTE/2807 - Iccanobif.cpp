// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Iccanobif
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2807

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
	
	int n; cin >> n;
	ll fib[44];
	fib[0] = 1, fib[1] = 1;
	for(int i=2; i<=n; i++) fib[i] = fib[i-1] + fib[i-2];
	
	for(int i=n-1; i>=0; i--){
		if(i!=n-1) printf(" ");
		printf("%lld", fib[i]);
	}	puts("");

	return 0;
}
