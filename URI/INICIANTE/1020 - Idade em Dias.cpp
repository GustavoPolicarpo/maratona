// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Idade em Dias
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1020

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int I, A, M, D;

int main()
{	
	cin >> I;
	
	
	A=I/365;
	M=(I-(A*365))/30;
	D=(I-(A*365+M*30));
		
	cout << A << " ano(s)" << endl;
	cout << M << " mes(es)" << endl;
	cout << D << " dia(s)" << endl;
	
	return(0);
}
