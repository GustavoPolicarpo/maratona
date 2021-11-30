// Author: Gustavo Policarpo
// Name: Christmas Decorations
// Level: 1
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1761

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;



int main()
{
	double A, B, C, pi=3.141592654;
	while(cin >> A >> B >> C)
	{
		cout << fixed << setprecision(2) 
			 << 5*(C+tan(A*pi/180)*B) << endl;	
	}
	
return 0;
}
