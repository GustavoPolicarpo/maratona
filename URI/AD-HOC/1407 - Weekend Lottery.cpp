// Author: Gustavo Policarpo
// Name: Weekend Lottery
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1407

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

int main()
{
	int N, C, K;
	
	while(scanf("%d %d %d", &N, &C, &K) and N+C+K){
		
		int n[K+1], aux, menor=INF;
		memset(n, 0, sizeof n);
		
		rep(i, 0, N)
		rep(j, 0, C){
			scanf("%d", &aux);
			n[aux]++;
		}
		
		rep(i, 1, K+1)
			if(n[i]<menor) menor=n[i];
			
		bool yep=false;
		
		rep(i, 1, K+1){
			if(n[i]==menor){
				if(yep) printf(" ");
				else yep=true;
				printf("%d", i);
			}
		}
		printf("\n");
	}	

	return 0;
	
}
