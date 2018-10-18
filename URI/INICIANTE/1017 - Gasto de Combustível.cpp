// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Gasto de Combustível
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1017

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int T, V;
double X, L;

int main()
{	
	cin >> T >> V;
	
	X=T*V;
	L=X/12;

	cout << fixed << setprecision(3);
	cout << L << endl;
	
	return(0);
}
