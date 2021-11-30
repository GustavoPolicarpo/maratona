// Author: Gustavo Policarpo
// Name: Below the Main Diagonal
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1184

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
	i=1; j=0;
	
	while(1)
	{
		S=S+M[i][j];
		i++;
		if(i==12)
		{
			j++;
			i=j+1;	
		}
		if(j==11 && i==12) break;	
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
