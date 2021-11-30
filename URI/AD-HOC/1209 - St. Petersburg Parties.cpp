// Author: Gustavo Policarpo
// Name: St. Petersburg Parties
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1209

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


typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned long long int ull;
typedef pair < int, ll > ii;
typedef pair < double, int > iii;
ll readInt();
int N, M, K, na[1001], mark[1001];
vector <int> adj[1001];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(scanf("%d %d %d", &N, &M, &K) !=EOF){
		rep(i, 0, N){
			na[i]=0, mark[i]=0, adj[i].clear();
		}
		int u, v;
		rep(i, 0, M){
			u=readInt(), v=readInt();
			u--, v--;
			adj[u].pb(v), adj[v].pb(u);
			na[u]++, na[v]++;
		}
		
		rep(i, 0, N){
			if(mark[i]) continue;
			if(na[i]<K){
				na[i]--, mark[i]=true;
				rep(j, 0, adj[i].size()){
					int v=adj[i][j];
					na[v]--;
				}
				i=-1;
			}
		}
		bool yep=true;
		rep(i, 0, N){
			if(!mark[i]){
				if(!yep) printf(" ");
				printf("%d", i+1);
				yep=false;
			}
		}
		if(yep) printf("0");
		printf("\n");
	}
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
