// Author: Gustavo Policarpo
// Name: KiloMan
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1250

#include<bits/stdc++.h>

using namespace std;


using namespace std;


int main()
{
	int N;
	cin >> N;
	while(N--)
	{
		int T;
		cin >> T;
		
		int S[T];
		long int NT=0;
		
		for(int i=0; i<T; i++) cin >> S[i];
		
		string C;
		cin >> C;
		
		for(int i=0; i<T; i++)
		{
			if(C[i]=='J' && S[i]>2) NT++;
			else if(C[i]=='S' && S[i]<=2) NT++;
		}
		cout << NT << endl;
		
	}
return(0);	
}
