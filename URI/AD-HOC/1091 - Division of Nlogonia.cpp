// Author: Gustavo Policarpo
// Name: Division of Nlogonia
// Level: 1
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1091

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

long int K, N, M, X, Y;


int main()
{
	while(1)
	{
		cin >> K;
		if(K==0) break;
		cin >> M >> N;
		while(K--)
		{
			cin >> X >> Y;
			
			if(X==M || Y==N) cout << "divisa" << endl;
			else if(X>M && Y>N) cout << "NE" << endl;
			else if(X<M && Y>N) cout << "NO" << endl;
			else if(X<M && Y<N) cout << "SO" << endl;
			else if(X>M && Y<N) cout << "SE" << endl;
		}
	}
	
	
			
				
			
	
return(0); 
}

