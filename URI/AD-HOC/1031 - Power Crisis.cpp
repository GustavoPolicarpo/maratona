// Author: Gustavo Policarpo
// Name: Power Crisis
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1031

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

int N;

int f(int n, int k)
{
	if(n==1) return 1;
	int v=(f(n-1,k)+k-1)%n+1;
	/*cout << v << endl;*/
	return v;	
}



int main()
{
	int N;
	while(cin >> N)
	{
		if(N==0) break;
		int K=1;
		while(1+f(N-1,K)!=13) K++;
		
		cout << K << endl;		
	}
	
return 0;
}
