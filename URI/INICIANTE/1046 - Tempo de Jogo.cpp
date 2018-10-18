// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tempo de Jogo
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1046

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int I, F;
int T;

int main()
{	
	cin >> I >> F;
	
	if (I>=F)
	{
		T=(24-I)+F;
	}
	else
	{
		T=F-I;
	}
	
	cout << "O JOGO DUROU " << T << " HORA(S)" << endl;
		
	return(0);
	
}
