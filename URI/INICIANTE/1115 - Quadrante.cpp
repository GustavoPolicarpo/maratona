// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Quadrante
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1115

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int X, Y, T;

int main()
{
	while(T==0)
	{
		cin >> X >> Y;
		if (X==0 || Y==0)
		{
			T=1;
		}
		else if (X>0 && Y>0)
		{
			cout << "primeiro" << endl;
		}
		else if (X<0 && Y>0)
		{
			cout << "segundo" << endl;
		}
		else if (X<0 && Y<0)
		{
			cout << "terceiro" << endl;
		}
		else if (X>0 && Y<0)
		{
			cout << "quarto" << endl;
		}
	}
	
return 0;	
}
