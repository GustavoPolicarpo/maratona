// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sort Simples
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1042

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int I1, I2, I3;
int A1, A2, A3;

int main()
{	
	cin >> I1 >> I2 >> I3;
	
	
	if (I1<I2 && I1<I3)
	{
		A3=I1;
	}
	else if (I1>I2 && I1>I3)
	{
		A1=I1;
	}
	else if ((I1>I2 && I1<I3) || (I1<I2 && I1>I3))
	{
		A2=I1;
	}
	
	if (I2<I1 && I2<I3)
	{
		A3=I2;
	}
	else if (I2>I1 && I2>I3)
	{
		A1=I2;
	}
	else if ((I2>I1 && I2<I3) || (I2<I1 && I2>I3))
	{
		A2=I2;
	}	
	
	if (I3<I1 && I3<I2)
	{
		A3=I3;
	}
	else if (I3>I1 && I3>I2)
	{
		A1=I3;
	}
	else if ((I3>I1 && I3<I2) || (I3<I1 && I3>I2))
	{
		A2=I3;
	}
	
	cout << A3 << endl << A2 << endl << A1 << endl;
	cout << endl;
	cout << I1 << endl << I2 << endl << I3 << endl;
			
	return(0);
}
