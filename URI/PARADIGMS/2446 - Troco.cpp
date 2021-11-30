// Author: Gustavo Policarpo
// Name: Troco
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2446

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


bool solve(int valor, int n, int *v){
	vector <int> al(valor+1, 0);
	al[0]=1;
	sort(v, v+n);
	for(int i=0; i<n; i++){
		for(int j=valor; j>=0; j--){
			if(!al[j]) continue;
			int k=v[i]+j;
			//cout << k << '\n';
			if(k==valor) return true;
			if(k<valor) al[k]=1;
		}
	}
	return false;
}
int main()
{
	int V, M;
	scanint(V), scanint(M); int n[M];
	rep(i, 0, M) scanint(n[i]);
	
	solve(V, M, n) ? puts("S") : puts("N");

	return 0;
	
}
