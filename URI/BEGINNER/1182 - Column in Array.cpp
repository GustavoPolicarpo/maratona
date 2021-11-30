// Author: Gustavo Policarpo
// Name: Column in Array
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1182

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double M[12][12];
int i=0, j=0;
int C;
double S;
char T;

int main()
{
	cin >> C >> T;
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
			S=S+M[i][C];
			i++;
		}
	}
	else if(T=='M')
	{
		for(int cont=1; cont<=12; cont++) 
		{
			S=S+M[i][C];
			i++;
		}
		S=S/12.0;
	}
	
	cout << fixed << setprecision(1) << S << endl;


return 0;

}
