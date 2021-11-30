// Author: Gustavo Policarpo
// Name: Exchanging Cards
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1104

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	int A, B;
	long int C[100000];
	while(cin >> A >> B)
	{
		if(A==0&&B==0) break;
		int a[100001], b[100001];
		for(int i=1; i<=100001; i++)
		{
			a[i]=0; b[i]=0;
		}
		int m=0;
		while(A--)
		{
			int temp; cin >> temp;
			if(m<temp) m=temp;
			a[temp]++;
		}
		while(B--)
		{
			int temp; cin >> temp;
			if(m<temp) m=temp;
			b[temp]++;
		}
		int TA=0, TB=0;
		for(int i=1; i<=m; i++)
		{
			//cout << a[i] << " " << b[i] << endl;
			if(a[i]==0&&b[i]>0)
				TB++;
			if(b[i]==0&&a[i]>0)
				TA++;
		}
		
		cout << (TA+TB-abs(TA-TB))/2 << endl;
		
	}
	
	return 0;
}
