// Author: Gustavo Policarpo
// Name: The Pythagorean Theorem
// Level: 5
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1582

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int X, Y, Z;

int main()
{
	while(cin >> X >> Y >> Z)
	{
		if(X*X==Y*Y+Z*Z || Y*Y==X*X+Z*Z || Z*Z==X*X+Y*Y)
		{
			int i=2;
			while(1)
			{
				if(X%i==0 && Y%i==0 && Z%i==0)
				{
					cout << "tripla pitagorica" << endl; break;
				}
				if(i>=X && i>=Y && i>=Z) 
				{
					cout << "tripla pitagorica primitiva" << endl; break;	
				}
				i++;
			}
		}
		else cout << "tripla" << endl;
		
	}
	
return (0);
}
