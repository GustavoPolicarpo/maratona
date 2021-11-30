// Author: Gustavo Policarpo
// Name: Harbin is Too Much Money!
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2103

#include<bits/stdc++.h>
#define gc getchar_unlocked


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
#define mod 1300031
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/
int N, n[10001], dist[10001];
vector <ii> adj[10001];

int dfs(int u, int last){

	rep(i, 0, adj[u].size()){
		int v=adj[u][i].F;
		if(v==last) continue;
		dist[v]=adj[u][i].S;
		n[u]++;
		n[u]+=dfs(v, u);
	}
	return n[u];
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int T; cin >> T;
	while(T--){
		scanf("%d", &N);
		rep(i, 1, N+1){
			adj[i].clear();
			n[i]=0, dist[i]=0;
		}
	
		int u, v, c;
		rep(i, 1, N){
			scanf("%d %d %d", &u, &v, &c);
			adj[u].pb(mp(v, c));
			adj[v].pb(mp(u, c));
		}
		dfs(1, 1);
		ll out=0;
		rep(i, 2, N+1){
			if(n[i]==0) out+=(dist[i]*(N-1));
			else out+=(dist[i]*(n[i]+1)*(N-n[i]-1));
			if(out>=1300031) out%=mod;
		}
		printf("%lld\n", out);
	}
	
return 0;	
}
