// Author: Gustavo Policarpo
// Name: Multiples of 13
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1132

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int X, Y, S;


int main()
{
	cin >> X >> Y;
	if(X>=Y)
	{
		for(Y; Y<=X; Y++)
		{
			if(Y%13!=0) { S=S+Y;
			}
		}
	}
	else
	{
		for(X; X<=Y; X++)
		{
			if(X%13!=0) { S=S+X;
			}
		}
	}
	cout << S << endl;
		
}
