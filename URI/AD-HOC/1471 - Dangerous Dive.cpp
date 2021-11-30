// Author: Gustavo Policarpo
// Name: Dangerous Dive
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1471

#include<bits/stdc++.h>

using namespace std;

int main()
{
	
	int N, R;
	while(cin >> N >> R)
	{
		int c[N];
		for(int i=0; i<N; i++) c[i]=0;
		for(int i=0; i<R; i++)
		{
			int temp;
			cin >> temp;
			c[temp-1]=1;
		}
		if(N==R) cout << '*';
		else
		for(int i=0; i<N; i++) 	if(c[i]==0) cout << i+1 << " ";
		
		cout << endl;
		
		
			
		
		
	}	
		
		
	
	
	
	
return (0);
}
