// Author: Gustavo Policarpo
// Name: Counting Crow
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1848

#include <iostream>
#include <cmath>
#include <stack>

using namespace std;

int R, piu=3;
char O[8];

int main()
{
while(piu>0)
{
	R=0;
	while(1)
	{	
		cin.getline(O, 8);
		
		if(O[0]=='c') { piu--; break; }
		
		else
		{
			stack <char> r;
			int pos=2;
			for(int i=0; i<3; i++) 
			{
				r.push(O[pos]);
				if(r.top()=='*') R=R+pow(2,i);
				r.pop();
				pos--;
			}	
		}	
			
	}
	cout << R << endl;
}

return(0);
}

