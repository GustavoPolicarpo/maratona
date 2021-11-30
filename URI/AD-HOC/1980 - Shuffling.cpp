// Author: Gustavo Policarpo
// Name: Shuffling
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1980

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	string T;
	while(cin >> T)
	{
		if(T=="0") break;
		long long int F=1;
		for(int i=T.size(); i>1; i--)
		{
			F*=i;
		}
		cout << F << endl;
		
			
	}
return(0); 
}


