// Author: Gustavo Policarpo
// Name: Fast Prime Number
// Level: 6
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1221

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stack>
#include <string.h>
#include <cctype>
#include <cstdlib>
#include <cstring>

using namespace std;

int N;
long int X, d=2;
bool prime=true;


int main()
{
	cin >> N;
	while(N--)
	{
		d=3;
		prime=true;
		cin >> X;
		if(X>2 && X%2==0) prime=false;
		else if(X>5 && X%5==0) prime=false;
		else
		{
			while(d<sqrt(X))
			{
				if(X%d==0) 
				{
					prime=false;
					break;
				}
				d=d+2;
			}
		}
		if(prime==true) cout << "Prime" << endl;
		else cout << "Not Prime" << endl;	
	}
return 0;
}


