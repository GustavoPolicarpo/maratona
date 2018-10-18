// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Linha na Matriz
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1181

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double M[12][12];
int i=0, j=0;
int L;
double S;
char T;

int main()
{
	cin >> L >> T;
	for(int cont=1; cont<=144; cont++)
	{
		cin >> M[i][j];
		j++; 
		if(j==12) 
		{
			j=0; i++;
		}
	}
	i=0; j=0;
	if(T=='S')
	{
		for(int cont=1; cont<=12; cont++) 
		{
			S=S+M[L][j];
			j++;
		}
	}
	else if(T=='M')
	{
		for(int cont=1; cont<=12; cont++) 
		{
			S=S+M[L][j];
			j++;
		}
		S=S/12.0;
	}
	
	cout << fixed << setprecision(1) << S << endl;


return 0;

}
