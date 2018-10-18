// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sequencia IJ 1
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1095

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int I=1, J=60;

int main()
{
	
	for(int con=60; con>=0; con=con-5)
	{
		cout << "I=" << I << " " << "J=" << J << endl;
		I=I+3; J=J-5;
	}
return 0;	
}
