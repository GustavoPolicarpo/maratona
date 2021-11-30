// Author: Gustavo Policarpo
// Name: Help Cupid
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1750

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



char s[1000010];

int main()
{
	// -10 -7 -5 -3 4 4 10 11
	int N; cin >> N;
	int n[N+2]; rep(i, 0, N) cin >> n[i];
	sort(n, n+N); n[N]=n[0];
	
	int a1=0, a2=0;
	rep(i, 0, N-1) a1+=min(abs(n[i]-n[i+1]), 24-abs(n[i]-n[i+1])), i++;
	rep(i, 1, N) a2+=min(abs(n[i]-n[i+1]), 24-abs(n[i]-n[i+1])), i++;
	
	cout << min(a1, a2) << '\n';
	
	return 0;
	
}
