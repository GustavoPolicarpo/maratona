// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Área Superior
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1187

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double M[12][12];
int i=0, j=0;
double S;
char O;

int main()
{
	cin  >> O;
	for(int cont=1; cont<=144; cont++)
	{
		cin >> M[i][j];
		j++; 
		if(j==12) 
		{
			j=0; i++;
		}
	}
	i=0; j=1; int posi=1, posf=11;
	
	while(1)
	{
		S=S+M[i][j];
		j++;
		if(j==posf)
		{
			posi++; posf--; j=posi;
			i++;
		}
		if(i==5) break;	
	}
	
	cout << fixed << setprecision(1);
	if(O=='S')
	{
		cout << S << endl;
	}
	else if(O=='M')
	{
		cout << S/30 << endl;
	}
	
return 0;

}
