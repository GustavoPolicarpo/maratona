// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fórmula de Bhaskara
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1036

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double A, B, C;
double R1, R2;
double DELTA;

int main()
{	

	cout << fixed << setprecision (5);

	cin >> A >> B >> C;
	
	DELTA = pow(B, 2)-4*A*C;
	
	if ( DELTA>=0 && A!=0 )
	{
		R1 = (-B+sqrt(DELTA))/(2*A);
		R2 = (-B-sqrt(DELTA))/(2*A);
		
		cout << "R1 = " << R1 << endl;
		cout << "R2 = " << R2 << endl;
	}
	else
	{
		cout << "Impossivel calcular" << endl;
	}
	
	return(0);
}
