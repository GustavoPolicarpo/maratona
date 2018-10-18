// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Animal
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1049

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

string T1, T2, T3; 

int main()
{	
	cin >> T1 >> T2 >> T3;
	if (T1=="vertebrado")
	{
		if(T2=="ave")
		{
			if(T3=="carnivoro")
			{
				cout<<"aguia"<<endl;
			}
			else if(T3=="onivoro")
			{
				cout<<"pomba"<<endl;
			}
		}
		else if(T2=="mamifero")
		{
			if(T3=="onivoro")
			{
				cout<<"homem"<<endl;
			}
			else if(T3=="herbivoro")
			{
				cout<<"vaca"<<endl;
			}
		}
	}
	else if (T1=="invertebrado")
	{
		if(T2=="inseto")
		{
			if(T3=="hematofago")
			{
				cout<<"pulga"<<endl;
			}
			else if(T3=="herbivoro")
			{
				cout<<"lagarta"<<endl;
			}
		}
		else if(T2=="anelideo")
		{
			if(T3=="hematofago")
			{
				cout<<"sanguessuga"<<endl;
			}
			else if(T3=="onivoro")
			{
				cout<<"minhoca"<<endl;
			}
		}
	}
	
}
