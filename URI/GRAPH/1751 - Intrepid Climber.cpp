// Author: Gustavo Policarpo
// Name: Intrepid Climber
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1751

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
typedef pair < double, int > iii;
ll readInt();
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, F, dist[1000001], cost[1000001], pai[1000001], ami[1000001], take[1000001];

int main()
{
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
	N=readInt(), F=readInt();
	dist[1]=0, pai[1]=0;
	int u, v, c;
	rep(i, 1, N){
		u=readInt(), v=readInt(), c=readInt();
		pai[v]=u, dist[v]=dist[u]+c, cost[v]=c;	
	}
	int far=1;
	rep(i, 0, F){
		u=readInt();
		ami[i]=u;
		if(dist[u]>dist[far]){
			far=u;
		}
	}
	while(pai[far]!=0){
		take[far]=1;
		far=pai[far];
	}
	int out=0;
	rep(i, 0, F){
		int aux=ami[i];
		while(!take[aux]){
			out+=cost[aux];
			take[aux]=1;
			aux=pai[aux];
		}
	}
	printf("%d\n", out);
	
				
return 0;
}

ll readInt(){
    int minus = 0;
    ll result = 0; char ch;

    ch = getchar();
    while(1){
        if( ch == '-' )
            break;
        if( ch >= '0' && ch <= '9' ) break;
        ch = getchar();
    }
    if( ch == '-' )  minus = 1;
    else result = ch-'0';
    while(1){
        ch = getchar();
        if( ch < '0' || ch > '9' ) break;
        result = result*10 + (ch-'0');
    }
    if( minus ) return -result;
    else return result;
}
