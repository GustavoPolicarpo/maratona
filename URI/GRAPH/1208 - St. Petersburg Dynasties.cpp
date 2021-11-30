// Author: Gustavo Policarpo
// Name: St. Petersburg Dynasties
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1208

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

int N, M, match[2002], vis[1001];
vector <int> adj[1001];

int aug(int u){
	if(vis[u]) return 0;
	vis[u]=1;
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(match[v]==-1 || aug(match[v])){
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(scanf("%d %d", &N, &M) !=EOF){
		int u, v;
		memset(match, -1, sizeof match);
		rep(i, 0, N+1) adj[i].clear();
		rep(i, 0, M){
			scanf("%d %d", &u, &v);
			u--, v--;
			adj[u].pb(v);
			//adj[v].pb(u);
		}
		int mcbm=0;
		rep(i, , N){
			rep(j, 0, N+1) vis[j]=0;
			mcbm+=aug(i);
		}
		printf("%d\n", N-mcbm);
	}
	

return 0;
}
