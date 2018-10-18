// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Agente 004
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1806

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


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

const int MAX=10010;
int N, C, S, B, dist[MAX], has[MAX], ans=0, ehds=-1;

vector <ii> adj1[MAX], adj2[MAX];

void solve1(int ini, int fim){
	rep(i, 1, N+1) dist[i]=INF;
	priority_queue <ii> pq;
	pq.push(mp(0, ini)), dist[ini]=0;
	
	while(!pq.empty()){
		int u=pq.top().S, c=-pq.top().F; pq.pop();
		//cout << u << " " << c << endl;
		
		if(u==fim){
			ehds=c;
			return;
		}
		
		rep(i, 0, adj1[u].size()){
			int v=adj1[u][i].F, cc=adj1[u][i].S;
			if(dist[v]<=c+cc) continue; dist[v]=c+cc;
			pq.push(mp(-(c+cc), v));
		}
		
	}
}

void solve2(int ini){
	priority_queue <ii> pq;
	rep(i, 1, N+1) dist[i]=INF;
	pq.push(mp(0, ini)), dist[ini]=0;
	
	while(!pq.empty()){
		int u=pq.top().S, c=-pq.top().F; pq.pop();
		
		if(c>ehds) return;
		//cout << u << " " << c << endl;
		ans+=has[u], has[u]=0;
		
		rep(i, 0, adj1[u].size()){
			int v=adj1[u][i].F, cc=adj1[u][i].S;
			if(dist[v]<c+cc) continue; dist[v]=c+cc;
			pq.push(mp(-(c+cc), v));
		}
		
		rep(i, 0, adj2[u].size()){
			int v=adj2[u][i].F, cc=adj2[u][i].S;
			if(dist[v]<c+cc) continue; dist[v]=c+cc;
			pq.push(mp(-(c+cc), v));
		}
		
	}
}

int main()
{
	scanint(N), scanint(C), scanint(S), scanint(B);
	int u, v, c;
	
	while(C--){
		scanint(u), scanint(v), scanint(c);
		adj1[u].pb(mp(v, c));
		adj1[v].pb(mp(u, c));
	}
	
	while(S--){
		scanint(u), scanint(v), scanint(c);
		adj2[u].pb(mp(v, c));
		adj2[v].pb(mp(u, c));
	}
	
	while(B--){
		scanint(u);
		has[u]++;
	}
	
	scanint(u), scanint(v);
	
	solve1(u, v);
	solve2(v);
	
	printf("%d\n", ans);
	




return 0;
}



