// Author: Gustavo Policarpo
// Name: Setting up a Date
// Level: 6
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2068

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F

typedef  long long int ll;
typedef pair < int, int > ii;

int main()
{
	ll t1, t2, N;
	cin >> t1 >> t2 >> N;
		
	ll tt=(t2-t1)*60;
	ll tf=tt-N;	
	
	ll num=tf*N+N*tt;
	ll den =tt*tt;
	
	ll gcd = __gcd(num, den);
	
	cout << num/gcd << "/" << den/gcd << endl;
		
}
