// Author: Gustavo Policarpo
// Name: Numbering Roads
// Level: 3
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1306

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;



int main()
{
	int R, N, i=0;
	while(cin >> R >> N)
	{
		if(R==0 && N==0) break;
		i++;
		cout << "Case " << i << ": ";
		if(N>=R) cout << 0;
		else
		{
			double temp=ceil(double(R-N)/N);
			if(temp>26) cout << "impossible";
			else cout << temp;
		}
		cout << endl;	
	}
	
	
return 0;
}
