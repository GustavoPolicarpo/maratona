// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Maior
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1013

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int a, b, c;
int M1, M2;

int main()
{	
	cin >> a >> b >> c;
	
	M1=(a+b+abs(a-b))/2;
	M2=(c+M1+abs(c-M1))/2;
	cout << M2 << " eh o maior" << endl;
	
	return(0);
}
