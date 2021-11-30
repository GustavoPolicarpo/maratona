// Author: Gustavo Policarpo
// Name: Alliteration
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1263

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{
	string T;
	while(getline(cin, T))
	{
		int a=0;
		vector <char> c;
		bool e=true;
		for(int i=0; i<T.size(); i++)
		{	
			if(isalpha(T[i])&&e==true)
			{
				c.push_back(tolower(T[i]));
				e=false;	
			} 
			else if(isspace(T[i])) e=true;
		}
		char p;
		for(int i=1; i<c.size(); i++)
		{
			p=c[i-2];
			if(c[i]==c[i-1] && c[i]!=p) a++;	
		}
		cout << a << endl;
	}
	
	
	
return(0); 
}


