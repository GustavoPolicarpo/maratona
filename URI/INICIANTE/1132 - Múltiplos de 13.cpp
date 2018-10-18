// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Múltiplos de 13
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1132

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int X, Y, S;


int main()
{
	cin >> X >> Y;
	if(X>=Y)
	{
		for(Y; Y<=X; Y++)
		{
			if(Y%13!=0) { S=S+Y;
			}
		}
	}
	else
	{
		for(X; X<=Y; X++)
		{
			if(X%13!=0) { S=S+X;
			}
		}
	}
	cout << S << endl;
		
}
