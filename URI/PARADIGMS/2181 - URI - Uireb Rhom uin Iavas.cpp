// Author: Gustavo Policarpo
// Name: URI - Uireb Rhom uin Iavas
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2181

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
typedef pair < int, double > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, D;

int main()
{
	scanf("%d %d", &N, &D);
	iii n[N];
	rep(i, 0, N) scanf("%d", &n[i].F);
	rep(i, 0, N) scanf("%lf", &n[i].S);
	sort(n, n+N);
	double sum[N], ms=0.0; int mg=0, g=1, last=-1;;
	rep(i, 0, N){
		int p=upper_bound(n, n+N, iii(n[i].F+D, INF)) -n;
		if(p!=N && p!=last) g++; last=p;
		if(i==0) sum[i]=n[i].S;
		else sum[i]=sum[i-1]+n[i].S;	
	}
	rep(i, 0, N){
		int p=upper_bound(n, n+N, iii(n[i].F+D, INF)) -n;
		mg=max(mg, p-i);
		if(i==0) ms=sum[p-1];
		else ms=max(ms, sum[p-1]-sum[i-1]);
	}
	printf("%d %d %.2lf\n", g, mg, ms);
	
		
return 0;
}
