// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Múltiplos
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1044

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int A, B;

int main()
{	
	cin >> A >> B;
	
	if(A%B==0 || B%A==0)
	{
		cout << "Sao Multiplos" << endl;
	}
	else
	{
		cout << "Nao sao Multiplos" << endl;
	}
			
	return(0);
}
