// Author: Gustavo Policarpo
// Name: Christmas Tree
// Level: 1
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1768

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;



int main()
{
	int N;
	while(cin >> N)
	{
		int e1=N/2, e2=N/2;
		for(int i=1; i<=N; i+=2, e1--)
		{
			for(int k=0; k<e1; k++)
				cout << ' ';
			for(int j=0; j<i; j++)
				cout << '*';
			cout << endl;
		}
		for(int k=0; k<e2; k++)
			cout << ' ';
		cout << '*' << endl;
		e2--;
		for(int k=0; k<e2; k++)
			cout << ' ';
		cout << "***" << endl;	
		
		cout << endl;	
	}
	
	
return 0;
}
