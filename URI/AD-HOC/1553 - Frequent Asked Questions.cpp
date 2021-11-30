// Author: Gustavo Policarpo
// Name: Frequent Asked Questions
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1553

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;



int main()
{
	int N, K;
	while(cin >> N >> K)
	{
		if(N==0&&K==0) break;
		int P[101];
		for(int i=0; i<100; i++) P[i]=0;
		for(int i=0; i<N; i++)
		{
			int temp;
			cin >> temp;
			P[temp-1]++;
		}
		int nq=0;
		for(int i=0; i<100; i++)
			if(P[i]>=K) nq++;
			
		cout << nq << endl;	
	}
	
return 0;
}
