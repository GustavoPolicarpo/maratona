// Author: Gustavo Policarpo
// Name: Below the Secundary Diagonal
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1186

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
	i=11; j=1; int pos=1;
	
	while(1)
	{
		S=S+M[i][j];
		j++;
		if(j==12)
		{
			pos++; j=pos;
			i--;
		}
		if(i==0) break;	
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
