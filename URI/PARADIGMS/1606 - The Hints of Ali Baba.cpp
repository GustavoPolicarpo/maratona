// Author: Gustavo Policarpo
// Name: The Hints of Ali Baba
// Level: 6
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1606

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

#define INF 0x3F3F3F3F3F3F3F
#define MAXV 100001
#define mod 1000000007
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
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



int K, N, aux, vis[100010];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(scanf("%d %d", &K, &N) !=EOF){
		bool yep=false;
		rep(i, 0, K){
			scanf("%d", &aux);
			if(!vis[aux]){
				if(yep) printf(" ");
				else yep=true;
				printf("%d", aux);
				vis[aux]=1;
			}
		}
		rep(i, 1, K+1) vis[i]=0;
		printf("\n");
	}

return 0;
}
