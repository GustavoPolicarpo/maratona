// Author: Gustavo Policarpo
// Name: Parenthesis Balance I
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1068

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	char E[10001];
	while(cin >> E)
	{
		int pa=1, pf=0;
		for(int i=0; i<strlen(E); i++)
		{
			if(E[i]=='(') pa++;
			else if(E[i]==')') pf++;
			
			if(pf==pa) break;
		}
		if(pa-1==pf) cout << "correct" << endl;
		else cout << "incorrect" << endl;
	}
		

	
		

		
	
		
	
	
	

	
		
return(0); 
}

