// Author: Gustavo Policarpo
// Name: Capital
// Level: 2
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2428

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


bool check(int a, int b, int c, int d){
	return a*b == c*d;
}

int main()
{
	int a1, a2, a3, a4, yep=0;
	cin>>a1>>a2>>a3>>a4;
	if(check(a1, a2, a3, a4) ||
	   check(a1, a3, a2, a4) ||
	   check(a1, a4, a2, a3) )
	   yep=1;
	   
	yep ? puts("S") : puts("N");

	return 0;
	
}
