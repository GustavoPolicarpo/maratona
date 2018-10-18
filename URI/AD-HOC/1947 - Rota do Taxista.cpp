// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Rota do Taxista
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1947

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
int N, M, K, grafo[16][16], custo[16], dist[100001], pd[16][1<<16];
vector <ii> adj[100001];

int minpath(int x, int y){
	if(x==y) return 0;
	memset(dist, INF, sizeof dist);
	dist[x]=0; priority_queue <ii> pq;
	pq.push(mp(0, x));
	while(!pq.empty()){
		int u=pq.top().S, c=-pq.top().F; pq.pop();
		if(u==y) return c;
		if(dist[u] != c) continue;
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F;
			int d=adj[u][i].S;
			if(dist[v]>dist[u]+d){
				dist[v]=dist[u]+d;
				pq.push(mp(-dist[v], v));
			}
		}
	}
}
int solve(int i, int mask){
	if(mask == (1<<K)-1) return grafo[i][0];
	int &p=pd[i][mask]; if(p!=-1) return p;
	int ret=INF;
	rep(j, 0, K){
		if(j!=i && !(mask&(1<<j)))
			ret=min(ret, solve(j, mask|(1<<j))+grafo[i][j]+custo[j]);
	}
	return p=ret;
}

int main()
{
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
	N=readInt(), M=readInt(), K=readInt();
	int u, v, c;
	rep(i, 0, M){
		u=readInt(), v=readInt(), c=readInt();
		adj[u].pb(mp(v, c));
		adj[v].pb(mp(u, c));
	} K++;
	ii n[K];
	n[0]=mp(1, 1);
	rep(i, 1, K){
		u=readInt(), v=readInt();
		n[i]=mp(u, v);
	}
	rep(i, 0, K)
	rep(j, 0, K){
		if(i==j) grafo[i][j]=0, custo[i]=minpath(n[i].S, n[j].F);
		else grafo[i][j]=minpath(n[i].S, n[j].F);	
		//cout << i << " " << j << " " << grafo[i][j] << endl;	
	}
	memset(pd, -1, sizeof pd);
	int out=solve(0, 0);
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

