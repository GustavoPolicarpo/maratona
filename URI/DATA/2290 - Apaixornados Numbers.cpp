// Author: Gustavo Policarpo
// Name: Apaixornados Numbers
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2290

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

void scanint(ll &x)
{
    register ll ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}




//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main()
{
	int n, aux;
	while(scanf("%d", &n) !=EOF){
		if(!n) break;
		
		ll v[n];
		rep(i, 0, n) scanint(v[i]);
		sort(v, v+n);
		
		int cnt=0;
		rep(i, 0, n-1){
			if(v[i]!=v[i+1]){
				if(!cnt) printf("%lld ", v[i]), cnt++;
				else{
					printf("%lld\n", v[i]);
					cnt++;
					break;
				}
			}
			else i++;
		}
		
		if(cnt==1) printf("%lld\n", v[n-1]);
	}
	
return 0;
}
