// Author: Gustavo Policarpo
// Name: Rock-paper-scissors-lizar...
// Level: 2
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1873

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
			if(B=="papel" || B=="lagarto") cout << "rajesh" << endl;
			else if(B=="pedra" || B=="spock") cout << "sheldon" << endl;
			else if(B=="tesoura") cout << "empate" << endl;
		}
		else if ( A=="papel")
		{
			if(B=="pedra" || B=="spock") cout << "rajesh" << endl;
			else if(B=="tesoura" || B=="lagarto") cout << "sheldon" << endl;
			else if(B=="papel") cout << "empate" << endl;
		}
		else if ( A=="pedra")
		{
			if(B=="lagarto" || B=="tesoura") cout << "rajesh" << endl;
			else if(B=="papel" || B=="spock") cout << "sheldon" << endl;
			else if(B=="pedra") cout << "empate" << endl;
		}
		else if ( A=="lagarto")
		{
			if(B=="spock" || B=="papel") cout << "rajesh" << endl;
			else if(B=="tesoura" || B=="pedra") cout << "sheldon" << endl;
			else if(B=="lagarto") cout << "empate" << endl;
		}
		else if ( A=="spock")
		{
			if(B=="tesoura" || B=="pedra") cout << "rajesh" << endl;
			else if(B=="lagarto" || B=="papel") cout << "sheldon" << endl;
			else if(B=="spock") cout << "empate" << endl;
		}		
	}	
return(0);
}

