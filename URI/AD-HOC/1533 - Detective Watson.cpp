// Author: Gustavo Policarpo
// Name: Detective Watson
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1533

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{

	int N;
	while(cin >> N)
	{
		if(N==0) break;
		vector <int> j;
		int J[N];
		for(int i=0; i<N; i++)
		{
			int temp;
			cin >> temp;
			j.push_back(temp);
			J[i]=temp;
		}
		int p=0;
		sort(j.begin(),j.end());
		for(int i=0; i<N; i++)
		{
			if(J[i]==j[N-2]) p=i+1;
		}
		cout << p << endl;
		
		
		
	}
	
	
return (0);
}
