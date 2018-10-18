// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Triangulação de Delaunay
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1620

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

long  double L, l, I, i;
long double X;
 

int main()
{
	while(1)
	{
		cin >> L;
		if(L==0) break;
		i=0;
		l=3;
		I=L+L-3;
		X=(I-L)/L;
		cout <<  fixed << setprecision(6) << X << endl;	
	}
	
	
return (0);
}
