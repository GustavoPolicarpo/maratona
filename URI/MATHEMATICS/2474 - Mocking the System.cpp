// Author: Gustavo Policarpo
// Name: Mocking the System
// Level: 9
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2474

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);




bool isPrime(ll n){
	
	if(n==2) return 1;
	if(n%2==0) return 0;
	
	for(int i=3; i<=sqrt(n); i+=2)
		if(n%i==0) return 0;
		
	return 1;
	
}

int main()
{
	ll n;
	while(scanf("%lld", &n)!=EOF){
		
		
		if(n%2==0 && n!=2){
			printf("%lld\n", n-2);
			continue;
		}
		
		if(isPrime(n)){
			printf("%lld\n", n-1);
			continue;
		}
		
		if(isPrime(n-2)){
			printf("%lld\n", n-2);
			continue;
		}
		
		printf("%lld\n", n-3);
		
	}
	
	return 0;
	
}
