// Author: Gustavo Policarpo
// Name: Pole Position
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1375

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;



int main()
{
	int n;
	while(cin >> n)
	{
		if(n==0) break;
		int e[n], t[n], p[n];
		for(int i=0; i<n; i++)
			p[i]=0;
		for(int i=0; i<n; i++)
		{
			int temp; 
			cin >> temp;
			e[i]=temp;
			cin>>temp;
			t[i]=temp;	
		}
		bool did=true;
		for(int i=0; i<n; i++)
		{
			int temp=i+t[i];
			//cout << temp << endl;
			if(temp>=n||temp<0) 
			{
				did=false;
				break;
			}
			else if(p[temp]!=0)	
			{
				did=false;
				break;
			}
			
			p[temp]=e[i];
		}
		if(did==false)
			cout << -1 << endl;
		else
		{
			for(int i=0; i<n-1; i++)
				cout << p[i] << " ";
			cout << p[n-1] << endl;
		}
		
			
	}
	
	
return 0;
}
