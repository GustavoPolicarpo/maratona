// Author: Gustavo Policarpo
// Name: Growing Sequences
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1146

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int X, cont;
bool FIM=false;

int main()
{
	while(FIM==false)
{
	cin >> X;
	if(X!=0)
	{
		for(cont=1; cont<=X; cont++)
		{
			while(cont<X)
			{
				cout << cont << " ";
				cont++;
			}
			cout << cont << endl;
		}
	}
	else { FIM=true;
	}
}
		
return 0;	
}
