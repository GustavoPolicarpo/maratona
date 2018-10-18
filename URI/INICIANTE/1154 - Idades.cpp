// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Idades
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1154

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


int main(int argc, char** argv) 
{
	double idade, soma, media;
	int cont;
	
	soma = 0;
	cont = 0;
	
	do
	{
		cin>>idade;
		if(idade>0)
		{
			soma = soma+idade;
			cont++;
		}	
		
	}
	while (idade>0);
	
	
	
	media = soma/cont;
	
	cout<<fixed<<setprecision(2);
	cout << media << endl;
	
	
	return 0;
}
