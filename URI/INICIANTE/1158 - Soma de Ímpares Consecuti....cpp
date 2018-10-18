// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Soma de Ímpares Consecuti...
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1158

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;
int X, Y;
int S;


int main()
{	
	cin >> N;
	
	for(int cont=1; cont<=N; cont++)
	{
		cin >> X >> Y;
		for(int cont2=1; cont2<=Y; cont2++)
		{
			if(X%2!=0) { S=S+X; X++;
			}
			else { X++; cont2--;
			}
		}
		cout << S << endl;
		S=0;
	}
	
return 0;	
}
