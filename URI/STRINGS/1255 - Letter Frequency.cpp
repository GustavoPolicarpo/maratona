// Author: Gustavo Policarpo
// Name: Letter Frequency
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1255

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int N;
	cin >> N ;
	cin.ignore();
	while(N--)
	{
		string T; int c[30];
		for(int i=0; i<26; i++) c[i]=0;
		getline(cin, T);
		for(int i=0; i<T.size(); i++)
		{
			if(isupper(T[i])) T[i]+=32;
			c[T[i]-'a']++;	
		}
		int M=0;
		for(int i=0; i<26; i++)
		{
			if(M<c[i]) M=c[i];
		}
		for(int i=0; i<26; i++)
		{
			if(c[i]==M)
			{
				char go=i+'a';
				cout << go;
			}
		}
		cout << endl;
		
		
	}
	
		

		
	
		
	
	
	

	
		
return(0); 
}

