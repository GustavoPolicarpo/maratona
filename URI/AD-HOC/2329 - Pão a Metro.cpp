// Author: Gustavo Policarpo
// Name: Pão a Metro
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2329

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
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;


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

int n[10010], N, K;

int ver(int k){
	int ret=0, i;
	i=lower_bound(n, n+K, k)-n;
	
	for(; i<K; i++) ret+=(n[i]/k);
	
	return ret;
}
int main ()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d %d", &N, &K);
	rep(i, 0, K) scanf("%d", &n[i]);
	
	sort(n, n+K);
	int ini=1, fim=n[K-1], use=(ini+fim+1)/2;
	while(fim-ini>1){
		int aux=ver(use);
		
		if(aux>N){
			ini=use;
			use=(ini+fim+1)/2;
		}
		else if(aux<N){
			fim=use;
			use=(ini+fim+1)/2;
		}
		else{
			while(ver(use)==N && use<=fim) use++;
			break;
		}
	}
	
	printf("%d\n", use-1);
	
  
  return 0;
}
