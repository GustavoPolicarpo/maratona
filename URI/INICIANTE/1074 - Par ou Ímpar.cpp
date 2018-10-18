// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Par ou Ímpar
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1074

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N, X;

int main()
{
	cin >> N;

	for(int con=0; con<N; con++)
	{
		cin >> X;
		if (X>0) 
		{
			if (X%2==0) { cout << "EVEN POSITIVE" << endl;
			}
			else { cout << "ODD POSITIVE" << endl;
			}
		}
		else if (X<0)
		{
			if (X%2==0) { cout << "EVEN NEGATIVE" << endl;
			}
			else { cout << "ODD NEGATIVE" << endl;
			}
		}
		else
		{
			cout << "NULL" << endl;
		}
		
	}
return 0;	
}
