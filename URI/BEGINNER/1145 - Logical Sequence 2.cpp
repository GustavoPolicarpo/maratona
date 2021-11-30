// Author: Gustavo Policarpo
// Name: Logical Sequence 2
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1145

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int X, Y;

int main()
{
	cin >> X >> Y;
	for(int con=1; con<=Y; con++)
	{
		
		for(int cont2=1; cont2<=X; cont2++)
		{
			if(con<=Y)
			{
				cout << con;	
				con++;
			}
			
			if(cont2<X)
			{
				cout << " ";
			}
		}	
		if(con<=Y)
			{
				con--;
				cout << endl;
			}

	}
	cout << endl;	
return 0;	
}
