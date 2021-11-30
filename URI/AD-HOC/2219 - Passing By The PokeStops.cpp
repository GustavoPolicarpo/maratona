// Author: Gustavo Policarpo
// Name: Passing By The PokeStops
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2219

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
	int T; scanint(T);
	while(T--){
		int N, M;
		//scanf("%d %d", &N, &M); 
		scanint(N), scanint(M);
		int ans=0, aux, last=0, m[M];
		
		rep(i, 0, M) scanint(m[i]);//scanf("%d", &m[i]);
		sort(m, m+M);
		rep(i, 0, M){	
			if(m[i]>N) break;
			if(m[i]-last>ans) ans=m[i]-last;
			last=m[i];
		}
		if(N-last>ans) ans=N-last;
		printf("%d\n", ans);
	}
	
	
	return 0;	
}
