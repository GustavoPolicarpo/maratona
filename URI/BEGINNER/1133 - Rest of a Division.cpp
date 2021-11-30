// Author: Gustavo Policarpo
// Name: Rest of a Division
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1133

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int X, Y;


int main()
{
	cin >> X >> Y;
	
	if (X>Y)
	{
		for (Y=Y+1; Y<X; Y++)
		{
			if(Y%5==2 || Y%5==3)
			{
				cout << Y << endl;;
			}
		}
	}
	else if (X<Y)
	{
		for (X=X+1; X<Y; X++)
		{
			if(X%5==2 || X%5==3)
			{
				cout << X << endl;
			}
		}
	}
	
	
return 0;	
}
