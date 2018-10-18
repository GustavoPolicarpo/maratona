// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Acima da Diagonal Principal
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1183

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
	i=0; j=1;
	
	while(1)
	{
		S=S+M[i][j];
		j++;
		if(j==12)
		{
			i++;
			j=i+1;	
		}
		if(i==11 && j==12) break;	
	}
	
	cout << fixed << setprecision(1);
	if(O=='S')
	{
		cout << S << endl;
	}
	else if(O=='M')
	{
		cout << S/((1+11)*11/2) << endl;
	}
	
return 0;

}
