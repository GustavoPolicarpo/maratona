// Author: Gustavo Policarpo
// Name: Curious Guardians
// Level: 10
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1937

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

const ll mod = 1e9+7;

#define MAXN 102
ll C[MAXN+1][MAXN+1];
void pascal(){
  rep (n, 0, MAXN+1){
    C[n][0] = C[n][n] = 1;
    rep(k, 1, n){
    	C[n][k] = C[n-1][k-1]+C[n-1][k];
      	C[n][k]%=mod;
	}
  }
}

ll pd[MAXN][MAXN];

int N, K;
ll solve(int n, int m){
	if(m==0) return 1;
	if(n==0 || m<0) return 0;
	if(pd[n][m]!=-1) return pd[n][m];
	
	ll ret=0;
	rep(k, 0, K){
		ret+=C[m][k]*solve(n-1, m-k);
		ret%=mod;
	}
	
	return pd[n][m]=ret;
	
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	pascal();
	cin >> N >> K;
	if(N==1){
		printf("%d\n", 1);
		return 0;
	}
	memset(pd, -1, sizeof pd);
	printf("%lld\n", solve(N, N-2));
	
	return 0;
	
}
