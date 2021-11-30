// Author: Gustavo Policarpo
// Name: Diamonds and Sand
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1069

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		char in[1001];
		cin >> in;
		int NC=0;
		//stack <char> c;
		int a=0, b=0;
		for(int i=0; i<strlen(in); i++)
		{
			if(in[i]=='<') a++;
			else if(in[i]=='>' && a>0) b++;
			if(a>0&&b>0)
			{
				NC++;
				a--;
				b--;
			}
		}
		cout << NC << endl;	
	}
		

	
		

		
	
		
	
	
	

	
		
return(0); 
}

