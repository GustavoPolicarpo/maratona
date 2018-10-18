// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Consumo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1014

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int X;
double Y, KM_L;


int main()
{	
	cin >> X >> Y;
	
	KM_L=X/Y;
	
	cout << fixed << setprecision(3);
	cout << KM_L << " km/l" << endl;
	
	return(0);
}
