// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Senha Fixa
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1114

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) 
{
	int senha;
	
	do
	{
		cin>>senha;
		if (senha != 2002)
		{
		cout<<"Senha Invalida"<<endl;
		}
	}
	while (senha != 2002);
	
		cout<<"Acesso Permitido"<<endl;
	
	return 0;
}

