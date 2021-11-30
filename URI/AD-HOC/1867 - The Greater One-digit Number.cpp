// Author: Gustavo Policarpo
// Name: The Greater One-digit Number
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1867

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;



int main()
{
	string N, M;
	char aux[] = {"0123456789"};
	while(cin >> N >> M)
	{
		if(N=="0" && M=="0") break;
		long int SA=0, SB=0;
		while(1)
		{
			for(int i=0; i<N.size(); i++) SA+=(N[i]-'0'); 
			N="";
			//cout << SA << endl;
			if( SA >= 10 )
			{
				N+=aux[abs(SA%10)];
				SA/=10;
			}
			else break;	
		}
		while(1)
		{
			for(int i=0; i<M.size(); i++) SB+=(M[i]-'0');
			M="";
			//cout << SB << endl;
			if( SB >= 10 )
			{
				M+=aux[abs(SB%10)];
				SB/=10;
			}	
			else break;
		}
		if(SA>SB) cout << 1 << endl;
		else if(SB>SA) cout << 2 << endl;
		else cout << 0 << endl;
		
				
		
	}
return(0); 
}


