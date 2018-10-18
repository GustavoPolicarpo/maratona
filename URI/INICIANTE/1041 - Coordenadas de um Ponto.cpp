// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Coordenadas de um Ponto
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1041

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double X, Y;

int main()
{	
	cin >> X >> Y;
		
	if(X>0 && Y>0)
	{
		cout << "Q1" << endl;	
	}
	else if(X<0 && Y>0)
	{
		cout << "Q2" << endl;
	}
	else if(X<0 && Y<0)
	{
		cout << "Q3" << endl;
	}
	else if(X>0 && Y<0)
	{
		cout << "Q4" << endl;
	}
	else if(X!=0 && Y==0)
	{
		cout << "Eixo X" << endl;
	}
	else if(X==0 && Y!=0)
	{
		cout << "Eixo Y" << endl;
	}	
	else
	{
		cout << "Origem" << endl;	
	}
				
	return(0);
}
