// Author: Gustavo Policarpo
// Name: The Law Goes on Horseback!
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2123

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
vector <int> adj[1000];
int match[20200];
int vis[1000], vv[1000];

int aug(int v)
{
	if(vis[v]==1) return 0;
	vis[v]=1;
	rep(j, 0, adj[v].size()){
		int r=adj[v][j];
		if(match[r]==-1 || aug(match[r])){
			match[r]=v;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int n, m, k, z=1;
	while(scanf("%d %d %d", &n, &m, &k) !=EOF){
		memset(match, -1, sizeof match);
		rep(i, 0, m+1) adj[i].clear();
		
		rep(i, 0, n) scanf("%d", &vv[i]);
		int s, c;
		rep(i, 0, k){
			c=readInt(), s=readInt();
			int aux=c*100+1;
			rep(j, 0, vv[c-1])
				adj[s-1].pb(aux++);
		}
		
		int mcbm=0;
		
		rep(i, 0, m){
			rep(j, 0, m+1)
				vis[j]=0;
			mcbm+=aug(i);
		}
		printf("Instancia %d\n%d\n\n", z++,mcbm);
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

