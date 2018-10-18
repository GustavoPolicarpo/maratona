// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Bazinga!
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1828

#include <iostream>
#include <cmath>

using namespace std;

int T;
string  A, B;


int main()
{
	cin >> T;
	for(int i=1; i<=T; i++)
	{
		A=""; B="";
		cin >> A >> B;
		if ( A=="tesoura")
		{
			if(B=="papel" || B=="lagarto") cout << "Caso #" << i << ": Bazinga!" << endl;
			else if(B=="pedra" || B=="Spock") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
			else if(B=="tesoura") cout << "Caso #" << i << ": De novo!" << endl;
		}
		else if ( A=="papel")
		{
			if(B=="pedra" || B=="Spock") cout << "Caso #" << i << ": Bazinga!" << endl;
			else if(B=="tesoura" || B=="lagarto") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
			else if(B=="papel") cout << "Caso #" << i << ": De novo!" << endl;
		}
		else if ( A=="pedra")
		{
			if(B=="lagarto" || B=="tesoura") cout << "Caso #" << i << ": Bazinga!" << endl;
			else if(B=="papel" || B=="Spock") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
			else if(B=="pedra") cout << "Caso #" << i << ": De novo!" << endl;
		}
		else if ( A=="lagarto")
		{
			if(B=="Spock" || B=="papel") cout << "Caso #" << i << ": Bazinga!" << endl;
			else if(B=="tesoura" || B=="pedra") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
			else if(B=="lagarto") cout << "Caso #" << i << ": De novo!" << endl;
		}
		else if ( A=="Spock")
		{
			if(B=="tesoura" || B=="pedra") cout << "Caso #" << i << ": Bazinga!" << endl;
			else if(B=="lagarto" || B=="papel") cout << "Caso #" << i << ": Raj trapaceou!" << endl;
			else if(B=="Spock") cout << "Caso #" << i << ": De novo!" << endl;
		}		
	}	
return(0);
}

