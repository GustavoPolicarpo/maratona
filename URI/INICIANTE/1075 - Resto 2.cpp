// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Resto 2
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1075

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;

int main()
{
	cin >> N;

	for(int con=1; con<=10000  ; con++)
	{
		if(con%N==2) { cout << con << endl;
		}	
	}
return 0;	
}
