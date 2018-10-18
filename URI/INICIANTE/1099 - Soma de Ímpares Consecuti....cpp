// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Soma de Ímpares Consecuti...
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1099

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N, X, Y, C;

int main()
{
	cin >> N;
	
	for(int con=0; con<N; con++)
	{
		C=0;
				
		cin >> X >> Y;
		
		if (X>Y)
		{ 
			for (Y=Y+1; Y<X; Y++)
			{
				if (Y%2==1)
				{
					C=C+Y;
				}
			}
		}
		else if (X<Y)
		{ 
			for (X=X+1; X<Y; X++)
			{
				if (X%2==1)
				{
					C=C+X;
				}
			}
		}
		else
		{
			C=0;
		}
		
		cout << C << endl;
	}
return 0;	
}
