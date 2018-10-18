// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Bactéria I
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2356

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)


//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	string d, s;
	while(cin >> d){
		cin >> s;
		int p = d.find(s);
		p == -1 ? puts("Nao resistente") : puts("Resistente");
	}
	
	return 0;
	
}
