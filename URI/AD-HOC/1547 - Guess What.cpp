// Author: Gustavo Policarpo
// Name: Guess What
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1547

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int main()
{
	long int N;
	cin >> N;
	while(N--)
	{
		int QT, S;
		cin >> QT >> S;
		int s=1000, m=1000;
		for(int i=0; i<QT; i++)
		{
			int temp; 
			cin >> temp;
			temp=abs(S-temp);
			if(m>temp)
			{
				m=temp;
				s=i;
			}  
		}
		cout << s+1 << endl;
	}
	
	
	
return(0);
}
 

