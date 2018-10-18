// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Validação de Nota
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1117

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) 
{
	double nota, soma, media;
	int cont;
	
	soma = 0;
	cont = 0;
	
	while (cont<2)
	{
	do
	{
		cin>>nota;
		if (nota < 0 || nota > 10)
		{
			cout<<"nota invalida"<<endl;
		}
	}
	while (nota < 0 || nota > 10);
	
	soma = soma + nota;
	cont++;
	}
	
	media = soma/cont;
	
	cout<<fixed<<setprecision(2);
	cout<<"media = "<<media<<endl;
	
	
	return 0;
}
