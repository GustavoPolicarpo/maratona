// Author: Gustavo Policarpo
// Name: Fake Tickets
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1318

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{

	int N, M;
	while(cin >> N >> M)
	{
		if(N==0 &&M==0) break;
		int b[N];
		for(int i=0; i<N; i++) b[i]=0;
		while(M--)
		{
			int temp;
			cin >> temp;
			b[temp-1]++;
		}
		int S=0;
		for(int i=0; i<N; i++)
		{
			if(b[i]>1) S++;
		}
		cout << S << endl;
		
	}
	
	
	
return (0);
}
