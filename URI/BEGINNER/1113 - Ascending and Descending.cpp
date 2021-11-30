// Author: Gustavo Policarpo
// Name: Ascending and Descending
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1113

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int X, Y, T;

int main()
{
	while(T==0)
	{
		cin >> X >> Y;
		
		if (X==Y)
		{
			T=1;
		}
		
		else if (X<Y)
		{
			cout << "Crescente" << endl;
		}
		
		else if (X>Y)
		{
			cout << "Decrescente" << endl;
		}	
	}
	
return 0;	
}
