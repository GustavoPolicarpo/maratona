// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: PUM
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1142

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N, SEQ=1;

int main()
{
	cin >> N;
	for(int con=1; con<=N; con++)
	{
		cout << SEQ << " " <<  SEQ+1 << " " << SEQ+2 << " PUM" << endl;
		SEQ=SEQ+4;
	}
	
	
return 0;	
}
