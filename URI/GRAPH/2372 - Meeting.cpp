// Author: Gustavo Policarpo
// Name: Meeting
// Level: 3
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2372

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
	int n, m; scanint(n), scanint(m);
	int dst[n][n];
	
	rep(i, 0, n)
	rep(j, 0, n){
		if(i==j) dst[i][i]=0;
		else dst[i][j]=INF;
	}
	
	int u, v, c;
	while(m--){
		scanint(u),scanint(v),scanint(c);
		if(dst[u][v]>c)	dst[u][v]=dst[v][u]=c;
	}
	
	rep(k, 0, n)
	rep(i, 0, n)
	rep(j, 0, n)
		dst[i][j]=min(dst[i][j], dst[i][k]+dst[k][j]);
	
	int ans=INF, aux=0;
	
	rep(i, 0, n){
		aux=0;
		rep(j, 0, n)
			aux=max(aux, dst[i][j]);
		ans=min(ans, aux);
	}
	
	printf("%d\n", ans);
	
}
