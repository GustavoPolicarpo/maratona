// Author: Gustavo Policarpo
// Name: Soma de Frações
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2443

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




int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	
	int num=a*d + b*c;
	int dem=b*d;
	
	int gcd=__gcd(num, dem);
	num/=gcd, dem/=gcd;
	
	cout << num << " " << dem << '\n';
	
	return 0;
	
}
