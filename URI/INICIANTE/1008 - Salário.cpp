// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Salário
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1008

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double P, SALARY;

int NUM, HRS;

int main()
{	
	cin >> NUM >> HRS >> P;
	
	SALARY = HRS*P;
	
	cout << "NUMBER = " << NUM << endl;	
	cout << fixed << setprecision(2);
	cout << "SALARY = U$ "<< SALARY << endl;
	
	return(0);
}
