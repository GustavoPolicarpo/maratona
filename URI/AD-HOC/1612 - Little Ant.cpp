// Author: Gustavo Policarpo
// Name: Little Ant
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1612

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int N;
	cin >> N;
	
	while(N--)
	{
		unsigned long int T;
		cin >> T;
		if(T%2==0) cout << T/2 << endl;
		else cout << (T+1)/2 << endl;
	}
	
	
return(0);
}

