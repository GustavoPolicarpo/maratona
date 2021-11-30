// Author: Gustavo Policarpo
// Name: Exceeding Z
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1150

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int X, Z, S, C;
bool ZM = false;


int main()
{
	cin >> X;
	while(ZM==false)
	{
		cin >> Z;
		if (Z>X)
		{
			ZM=true;
		}
	}
	for(S; S<Z; X++)
	{
		S=S+X;	
		C++;
	}
	cout << C << endl;
		
return 0;	
}
