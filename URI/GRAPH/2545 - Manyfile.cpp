// Author: Gustavo Policarpo
// Name: Manyfile
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2545

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;


int N;
int grau[1010], vis[1010];
vector <int> adj[1010];


int solve(){
	
	queue <ii> q;
	rep(i, 1, N+1){
		if(grau[i]==0){
			q.push(mp(i, 1));
		}
	}
	
	int ret;
	while(!q.empty()){
		int u=q.front().F, t=q.front().S; q.pop();
		
		ret=t;
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			grau[v]--;
			if(grau[v]==0){
				q.push(mp(v, t+1));
			}
		}
		
	}
	
	rep(i, 1, N+1) if(grau[i]) return -1;
	
	return ret;
		
}

int main()
{
	
	while(scanf("%d", &N)!=EOF){
		
		rep(i, 0, N+2){
			adj[i].clear();
			grau[i]=0;
			vis[i]=0;
		}
		
		int M, u;
		rep(i, 1, N+1){
			scanf("%d", &M);
			while(M--){
				scanf("%d", &u);
				grau[i]++;
				adj[u].pb(i);
			}
		}
		
		printf("%d\n", solve());
		
	}


	return 0;
	
}
