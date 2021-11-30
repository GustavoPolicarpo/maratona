// Author: Gustavo Policarpo
// Name: Sum of Two Squares
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1558

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

void go(int n)
{
	bool did=false;
	if(n<0) cout << "NO" << endl;
	else
	{
		for(int i=0; i<=sqrt(n); i++)
		{
			for(int j=0; j<=sqrt(n); j++)
			{
				if(i*i+j*j==n)
				{
					cout << "YES" << endl;
					did=true;
					break;
				}
			}
			if(did==true) break;
		}
	if(did==false) cout << "NO" << endl;
	}
	
	return;
}


int main()
{
	int n;
	while(cin >> n)
	{
		go(n);		
	}
	
	
return 0;
}
