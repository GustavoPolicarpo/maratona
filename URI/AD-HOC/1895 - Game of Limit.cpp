// Author: Gustavo Policarpo
// Name: Game of Limit
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1895

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;



int main()
{
	int N, T, L;
	cin >> N >> T >> L;
	int d, PA=0, PB=0;
	N-=1;
	for(int i=0; i<N; i++)
	{
		int temp;
		cin >> temp;
		int value=abs(T-temp);
		if (value<=L)
		{
			if(i%2==0) PA+=value;
			else PB+=value;
			T=temp;
		}
	}
	cout << PA << " " << PB << endl;
	
	
	
return(0); 
}


