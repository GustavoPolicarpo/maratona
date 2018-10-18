// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Goão e Escadas
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2119

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second


#define MAXV 100001


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, ll > ii;
typedef pair < ll, int > iii;

ll INF = 1LL<<50;
const ll mod =1e9 + 9;

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

int N, M, K;
int n[1001]; ll pd[1001], dist[10001];

vector <ii> adj[10001];

ll solve(int deg){
	if(deg<0) return 0;
	if(deg==0) return 1;
	
	if(pd[deg]!=-1) return pd[deg];
	
	ll ret=0;
	rep(i, 0, K){
		if(deg-n[i]<0) break;
		ret+=solve(deg-n[i]);
		ret%=mod;
	}
	
	return pd[deg]=ret;
}

ll dijsktra(){
	priority_queue <iii> pq;
	pq.push(mp(INF, 0)); dist[0]=INF;
	
	while(!pq.empty()){
		int u=pq.top().S; ll c=pq.top().F; pq.pop();
		
		if(u==N-1) return c;
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F; ll cc=adj[u][i].S;
			if(dist[v]>=min(cc, c)) continue;
			dist[v]=min(cc, c);
			pq.push(mp(dist[v], v));
		}
	}
	
	return 0;

}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	rep(i, 0, K) scanf("%d", &n[i]);
	sort(n, n+K);
	
	memset(pd, -1, sizeof pd);
		
	int u, v, c; ll cc;
	rep(i, 0, M){
		scanf("%d %d %d", &u, &v, &c);
		cc=solve(c);
		adj[u].pb(mp(v, cc));
		adj[v].pb(mp(u, cc));
	}
	
	printf("%lld\n", dijsktra());
	

	return 0;
	
}
