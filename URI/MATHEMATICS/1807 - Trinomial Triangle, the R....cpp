// Author: Gustavo Policarpo
// Name: Trinomial Triangle, the R...
// Level: 5
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1807

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED
//2147483647

#define mod 2147483647

using namespace std;

int fast_pow(int b, int r)
{
	if(r==0) return 1;
	unsigned long long int go=fast_pow(b,r/2);
	go=(go%mod*go%mod)%mod;
	if(r%2==1) go=(go*b)%mod;
	return go;	
}

int main()
{
	int R;
	cin >> R;
	cout << fast_pow(3,R) << endl;	
return 0;
}
