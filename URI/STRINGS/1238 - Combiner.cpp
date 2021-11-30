// Author: Gustavo Policarpo
// Name: Combiner
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1238

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int N, tama, tamb;
string A, B;

int main()
{
	cin >> N;
	while(N--)
	{
		cin >> A >> B;
		tama=A.size();
		tamb=B.size();
		if(tama>tamb)
		{
			for (int i=0; i<tamb; i++)
			{
				cout << A[i];
				cout << B[i];
			}
			
			for (int i=tamb; i<tama; i++)
			{
				cout << A[i];
			}
		}
		else if(tama<tamb)
		{
			for (int i=0; i<tama; i++)
			{
				cout << A[i];
				cout << B[i];
			}
			for (int i=tama; i<tamb; i++)
			{
				cout << B[i];
			}
		}
		else
		{
			for (int i=0; i<tamb; i++)
			{
				cout << A[i];
				cout << B[i];
			}
			
		}
		cout << endl;
		
		
	}
}
