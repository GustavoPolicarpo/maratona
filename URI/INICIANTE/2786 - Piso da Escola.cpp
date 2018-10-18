// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Piso da Escola
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2786

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
	
	int l, c; cin >> l >> c;
	int t1 = l*c + (l-1)*(c-1);
	int t2 = (l-1 + c-1)*2;
	
	cout << t1 << "\n" << t2 << '\n';
	
	return 0;
}
