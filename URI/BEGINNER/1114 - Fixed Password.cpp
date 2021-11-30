// Author: Gustavo Policarpo
// Name: Fixed Password
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1114

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

