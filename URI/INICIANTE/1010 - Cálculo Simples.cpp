// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cálculo Simples
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1010

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double CP1, NP1, VP1, CP2, NP2, VP2, T;

int main()
{	
	cin >> CP1 >> NP1 >> VP1 >> CP2 >> NP2 >> VP2;
	
	T = NP1*VP1 + NP2*VP2;
	
	cout << fixed << setprecision(2);
	cout << "VALOR A PAGAR: R$ "<< T << endl;
	
	return(0);
}
