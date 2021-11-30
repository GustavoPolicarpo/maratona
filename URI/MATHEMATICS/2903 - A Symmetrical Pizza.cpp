// Author: Gustavo Policarpo
// Name: A Symmetrical Pizza
// Level: 7
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2903

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;




int main(){
	
	ll a, b;
	scanf("%lld.%lld", &a, &b);
	ll n = a*100+b;
	ll ans = (n*36000)/(__gcd(n, 36000LL))/n;
	
	cout << ans << '\n';
	
	
	

	return 0;
} 
