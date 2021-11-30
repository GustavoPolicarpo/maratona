// Author: Gustavo Policarpo
// Name: Radars
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1689

#define gc getchar_unlocked
#include<bits/stdc++.h>

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

int N, K, p[1000001], v[1000001], pd[1000001];

int solve(int i)
{
	if(i>=N) return 0;
	if(pd[i]!=-1) return pd[i];
	
	int pos = lower_bound(p, p+N, p[i]+K) - p;
	
	int ret=max(solve(i+1), solve(pos)+v[i]);
	
	return pd[i]=ret;
}

int main ()
{
	int T; scanint(T);
	while(T--){
			
		scanint(N);
		scanint(K);
		
		rep(i, 0, N)
			scanint(p[i]), pd[i]=-1;
				
		rep(i, 0, N)
			scanint(v[i]);
			
		int out=0;

		out=solve(0);
				
		printf("%d\n", out);
	}
		
return 0;
}
