// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Entrada e Saída Lendo e P...
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2766

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define pb push_back
#define F first
#define S second

using namespace std;

typedef pair<int, int> ii;



int main(){
	
	vector <string> v; string s;
	rep(i, 0, 10){
	    cin >> s;
	    v.pb(s);
	}
	
	cout << v[2] << '\n' << v[6] << '\n' << v[8] << '\n';
	
    return 0;
}
