// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Divisores I
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1157

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int N;


int main()
{	
	cin >> N;
	
	for(int cont=1; cont<=N; cont++)
	{
		if(N%cont==0)
		{
			cout << cont << endl;
		}
	}
	
return 0;	
}
