// Author: Gustavo Policarpo
// Name: Lost Boots
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1245

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int main()
{

	int N;
	while(cin >> N)
	{
		int M[2][31];
		for(int i=0; i<2; i++)
		{
			for(int j=0; j<=30; j++) M[i][j]=0;
		}
		int num; char p;
		while(N--)
		{
			cin >> num >> p;
			int i;
			if(p=='D')i=0;
			else i=1;
			M[i][num-30]++;
		}	
		int S=0;
		for(int j=0; j<=30; j++)
		{
			while(M[0][j]>0&&M[1][j]>0)
			{
				S++;
				M[0][j]--; M[1][j]--;
			}
		}
		cout << S << endl;
	}	
		
		
	
	
	
	
return (0);
}
