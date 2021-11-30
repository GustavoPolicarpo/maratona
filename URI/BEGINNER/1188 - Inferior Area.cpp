// Author: Gustavo Policarpo
// Name: Inferior Area
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1188

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
	i=11; j=1; int posi=1, posf=11;
	
	while(1)
	{
		S=S+M[i][j];
		j++;
		if(j==posf)
		{
			posi++; posf--; j=posi;
			i--;
		}
		if(i==6) break;	
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
