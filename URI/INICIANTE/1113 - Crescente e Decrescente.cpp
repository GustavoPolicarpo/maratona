// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Crescente e Decrescente
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1113

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
		
		if (X==Y)
		{
			T=1;
		}
		
		else if (X<Y)
		{
			cout << "Crescente" << endl;
		}
		
		else if (X>Y)
		{
			cout << "Decrescente" << endl;
		}	
	}
	
return 0;	
}
