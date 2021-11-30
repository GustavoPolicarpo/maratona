// Author: Gustavo Policarpo
// Name: Getline One
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1216

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

string N;
long double D, cont, S, M;

int main()
{
	while(getline(cin,N))
	{
		cin >> D;
		cin.ignore();
		cont++;		
		S=S+D; 	
	}
	
	M=S/cont;
	cout << fixed << setprecision(1) << M << endl;

return(0);	
}	 
		
	



