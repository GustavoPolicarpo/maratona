// Author: Gustavo Policarpo
// Name: Oracle of Alexandria
// Level: 1
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1457

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;



int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		char IN[25];
		cin >> IN;
		int p;
		for(int i=0; i<strlen(IN); i++) if(IN[i]=='!') {p=i; break;}
		int n=0;
		for(int i=0; i<p; i++)
		{
			n+=pow(10,p-i-1)*(IN[i]-'0');	
		}
		int k=strlen(IN)-p;
		unsigned long long int S=1;
		int go=n;
		while(go>=1)
		{
			S*=go;
			go-=k;
		}
		cout << S << endl;
				
		
	}
return(0); 
}


