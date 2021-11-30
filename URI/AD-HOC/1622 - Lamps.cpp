// Author: Gustavo Policarpo
// Name: Lamps
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1622

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

 
int main()
{
	int N, Q;
	while(cin >> N >> Q)
	{
		if(N==0&&Q==0) break;
		string T;
		cin >> T;
		int L[N];
		for(int i=0; i<N; i++)
		{
			if(T[i]=='x')
				L[i]=0;
			else
				L[i]=1;
		}
		while(Q--)
		{
			int l[N];
			for(int i=0; i<N; i++)
				l[i]=L[i];
				
			int K, M;
			cin >> K >> M;
			int p=0;
			M=M%(2*N);
			while(M>0)
			{
				if(l[p]==1)
					l[p]=0;
				else
					l[p]=1;
					
				p+=K;
				if(p>=N)
					p=p-N;
				M--;	
			}		
			for(int i=0; i<N; i++)
			{
				if(l[i]==1)
					cout << 'o';
				else cout << 'x';
			}
			cout << endl;
		}
	}
	
return 0;
}

