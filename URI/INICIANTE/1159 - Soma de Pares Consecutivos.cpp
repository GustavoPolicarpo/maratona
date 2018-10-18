// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Soma de Pares Consecutivos
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1159

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int X;
int S;
bool loop=true;


int main()
{	
	while(loop==true)
	{
		cin >> X;
		if(X==0)
		{
			loop=false;
		}
		else
		{
			for(int cont2=1; cont2<=5; cont2++)
			{
				if(X%2==0) { S=S+X; X++;
				}
				else { X++; cont2--;
				}
			}
			cout << S << endl;
			S=0;
		}
	}
	
return 0;	
}
