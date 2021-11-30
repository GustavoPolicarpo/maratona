// Author: Gustavo Policarpo
// Name: The Time Room
// Level: 6
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1754

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		unsigned long long int  X, Y;
		cin >> X >> Y;
		unsigned long long int k;
		if(Y>=X)
			 k=2;
		else	
		{
			k=X/Y;
			if(X%Y>0) 
				k++;
		}	
		cout << k << endl;
	}
		

return 0;
}
