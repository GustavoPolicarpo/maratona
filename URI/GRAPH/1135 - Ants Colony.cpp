// Author: Gustavo Policarpo
// Name: Ants Colony
// Level: 8
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1135

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


int nivel[1000001];
int pai[1000001];
ll cost[100001];
ll out;

int coni(int &a, int &b)
{
	if(nivel[a]>nivel[b]){
		int aux=nivel[a]-nivel[b];
		while(aux--){
			out+=cost[a];
			a=pai[a];
		}
	}
	else if(nivel[b]>nivel[a]){
		int aux=nivel[b]-nivel[a];
		while(aux--){
			out+=cost[b];
			b=pai[b];
		}
	}
	
}

void copa(int a, int b)
{
	if(a!=b){
		out=out+cost[a]+cost[b];
		while(pai[a]!=pai[b]){
		
			a=pai[a];
			b=pai[b];
			out=out+cost[a]+cost[b];
		}	
	}			
}

int main()
{
	int N;
	while(1){
		scanint(N);
		if(!N) break;
		
		int u; int c;
			scanint(u), scanint(c);
			nivel[u]=0;
			pai[1]=u;
			nivel[1]=nivel[u]+1;
			cost[1]=c;
		
		rep(i, 2, N){
			scanint(u), scanint(c);
			pai[i]=u;
			nivel[i]=nivel[u]+1;
			cost[i]=c;
		}
		
		int Q;
		scanf("%d", &Q);
		int a, b;
		bool mark=false;
		while(Q--){
			
			if(mark)
				printf(" ");
			else
				mark=true;
			out=0;
			scanint(a), scanint(b);
			coni(a, b);
			copa(a, b);
			printf("%lld", out);
		}
		printf("\n");
	}
}
