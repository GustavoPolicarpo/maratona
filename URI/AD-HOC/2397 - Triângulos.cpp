// Author: Gustavo Policarpo
// Name: Triângulos
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2397

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




int main()
{
	int n[3];
	cin >> n[0] >> n[1] >> n[2];
	sort(n, n+3);
	reverse(n, n+3);
	
	if(n[0] >= n[1] + n[2]) puts("n");
	else if (n[0]*n[0] == n[1]*n[1] + n[2]*n[2]) puts("r");
	else if (n[0]*n[0] > n[1]*n[1] + n[2]*n[2]) puts("o");
	else if (n[0]*n[0] < n[1]*n[1] + n[2]*n[2]) puts("a");
	
	
	return 0;
	
}
