// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Mania de Par
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1931

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
ll readInt();
int vis[100001][2], dist[100001][2], C, V;
vector <ii> adj[100001];

int dijsktra(){
	memset(dist, INF, sizeof dist);
	priority_queue <iii> pq;
	pq.push(mp(0, mp(0, 1))); dist[1][0]=0;
	
	while(!pq.empty()){
		int u=pq.top().S.S, c=pq.top().S.F, d=-pq.top().F; pq.pop();
		//cout << u << " " << c << endl;
		if(u==C && c==0){
			return d;
		}
		if(dist[u][c]!=d) continue;
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F;
			int e=adj[u][i].S;
			if(dist[v][1-c]>dist[u][c]+e){
				dist[v][1-c]=dist[u][c]+e;
				pq.push(mp(-dist[v][1-c], mp(1-c, v)));
			}	
		}	
	}
	return -1;	
}
int main(){
	C=readInt(), V=readInt();
	int u, v, c;
	rep(i, 0, V){
		u=readInt(), v=readInt(), c=readInt();
		adj[u].pb(mp(v, c));
		adj[v].pb(mp(u, c));
	}
	int out=dijsktra();
	cout << out << endl;
	
				
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
