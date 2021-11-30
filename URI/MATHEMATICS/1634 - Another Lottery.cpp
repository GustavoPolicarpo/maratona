// Author: Gustavo Policarpo
// Name: Another Lottery
// Level: 5
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1634

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define f(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(c) c.begin(), c.end() 

typedef pair<char, int> ii;
typedef pair<pair<double, int>, ii> iii;
typedef unsigned long long int ll;


int mat[10001][33];

int main()
{
	
	int n, m;
	
	while(scanf("%d %d", &n, &m) and n+m){
		
		rep(i, 0, n) rep(j, 0, m) scanf("%d", &mat[i][j]);
		
		ll total=0;
		rep(i, 0, n) total+=mat[i][m-1];
		
		rep(i, 0, n){
			ll num=mat[i][m-1], dem=total;
			ll aux=__gcd(num, dem);
			printf("%lld / %lld\n", num/aux, dem/aux);
		}
		
	}
	
	
	return 0;
	
}
