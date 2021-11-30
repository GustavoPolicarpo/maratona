// Author: Gustavo Policarpo
// Name: Sticks Game
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1366

# include <bits/stdc++.h>

using namespace std;

int main()
{
	
	int N;
	while(cin>>N)
	{
		if(N==0) break;
		long int soma=0;
		int tam, qt;
		while(N--)
		{
			cin >> tam >> qt;
			if(qt%2!=0) qt--;
			
				soma=soma+qt;

		}
		cout << soma/4 << endl;
	}



	return 0;
}

