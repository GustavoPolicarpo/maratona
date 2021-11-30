// Author: Gustavo Policarpo
// Name: Caesar Cipher
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1253

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N, A;
	cin >> N;
	cin.ignore();
	
	while(N--)
	{
		string t; int go;
		
		cin >> t;
		cin.ignore();
		cin >> go;
		cin.ignore();
		
		for(int i=0; i<t.size(); i++)
		{
			int aux=go;
			if(t[i]-go<65)
			{
				aux=t[i]-65;
				t[i] =91;	
			}
			else aux=0;
			
			t[i] -= go-aux;
			
			
		}
		cout << t << endl;
	}
	
	
return(0);
}

