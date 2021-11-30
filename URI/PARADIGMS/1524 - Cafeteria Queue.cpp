// Author: Gustavo Policarpo
// Name: Cafeteria Queue
// Level: 4
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1524

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

#define INF 0x3F3F3F3F3
#define MAXV 100001

#define error 1e-9

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
	int N, K;
	while(scanf("%d %d", &N, &K) !=EOF){
		int n[N], d[N], o[N], ans=0;
		n[0]=d[0]=o[0]=0;
		
		rep(i, 1, N){
			scanf("%d", &n[i]);
			d[i]=o[i]=n[i]-n[i-1];
		}
		
		sort(o, o+N);
		reverse(o, o+N);
		
		rep(i, K-1, N){
			ans+=o[i];
		}
			
		printf("%d\n", ans);
	}
	
	return 0;	
}
