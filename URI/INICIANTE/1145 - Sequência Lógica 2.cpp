// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sequência Lógica 2
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1145

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int X, Y;

int main()
{
	cin >> X >> Y;
	for(int con=1; con<=Y; con++)
	{
		
		for(int cont2=1; cont2<=X; cont2++)
		{
			if(con<=Y)
			{
				cout << con;	
				con++;
			}
			
			if(cont2<X)
			{
				cout << " ";
			}
		}	
		if(con<=Y)
			{
				con--;
				cout << endl;
			}

	}
	cout << endl;	
return 0;	
}
