// Author: Gustavo Policarpo
// Name: Pens
// Level: 8
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2494

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second


typedef long long int ll;
typedef pair < int, int > ii;


int main()
{	
	
	int a, b, c;
	while(cin >> a >> b >> c){
		int mdc=__gcd(a, b), ans=a/mdc + b/mdc;
		ans >= c ? puts("sim") : puts("nao");
	}
	
	return 0;
	
}
