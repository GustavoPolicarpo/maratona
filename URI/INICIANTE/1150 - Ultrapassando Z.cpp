// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ultrapassando Z
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1150

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int X, Z, S, C;
bool ZM = false;


int main()
{
	cin >> X;
	while(ZM==false)
	{
		cin >> Z;
		if (Z>X)
		{
			ZM=true;
		}
	}
	for(S; S<Z; X++)
	{
		S=S+X;	
		C++;
	}
	cout << C << endl;
		
return 0;	
}
