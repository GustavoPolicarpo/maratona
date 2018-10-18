// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sequencia IJ 4
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1098

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double I=0, J=1;

int main()
{
	
	for(int con=10; con>=0; con=con-1)
	{
		cout << "I=" << I << " " << "J=" << J << endl;
		I=I; J=J+1;
		cout << "I=" << I << " " << "J=" << J << endl;
		I=I; J=J+1;
		cout << "I=" << I << " " << "J=" << J << endl;
		I=I+0.2; J=J-2+0.2;
	}
return 0;	
}
