// Author: Gustavo Policarpo
// Name: Robert and Rampant Room
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1953

#include<bits/stdc++.h>

using namespace std;

int main()
{
	long int N;
	while(cin >> N)
	{
		cin.ignore();
		string MAT, SIG;
		long int EPR=0, EHD=0, INT=0;
		while(N--)
		{
			cin >> MAT >> SIG;
			if(SIG=="EPR") EPR++;
			else if(SIG=="EHD") EHD++;
			else INT++;	
		}
		cout << "EPR: " << EPR << endl;
		cout << "EHD: " << EHD << endl;
		cout << "INTRUSOS: " << INT << endl;
	}
	
	
return(0);
}

