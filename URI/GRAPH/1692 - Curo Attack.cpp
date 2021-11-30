// Author: Gustavo Policarpo
// Name: Curo Attack
// Level: 10
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1692

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

vector <int> adj[1010];
vector <ii> edg;

bool canGet(int u, int last, int k, int t){
	if(t==k) return true; int ret = false;
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		if(v==last) continue;
		ret |= canGet(v, u, k, t+1);
	}
	return ret;
}

int take(int u, int last, int k, int t){
	int ret = 1; if(t==k) return ret;
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		if(v==last) continue;
		ret += take(v, u, k, t+1);
	}
	return ret;
}

int main(){
	
	int n, k;
	while(scanf("%d %d", &n, &k)!=EOF){
		rep(i, 0, n+2) adj[i].clear(); edg.clear();
		
		int u, v;
		rep(i, 1, n){
			scanf("%d %d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
			edg.pb(ii(u, v));
		}
		
		int ans = -1;
		rep(i, 0, edg.size()){
			u = edg[i].F, v = edg[i].S;
			if(k&1){
				int up = k/2, down = k/2;
				if(canGet(u, v, up, 0) && canGet(v, u, down, 0)){
					ans = max(ans, take(u, v, up, 0) + take(v, u, down, 0));
				}
			}else{
				int up = (k-1)/2, down = k/2;
				if(canGet(u, v, up, 0) && canGet(v, u, down, 0)){
					ans = max(ans, take(u, v, up, 0) + take(v, u, down, 0));
				}
				swap(u, v);
				if(canGet(u, v, up, 0) && canGet(v, u, down, 0)){
					ans = max(ans, take(u, v, up, 0) + take(v, u, down, 0));
				}
			}
		}
		
		if(ans==-1) puts("Impossible revenge!");
		else printf("%d\n", ans);
		
	}

	
	return 0;
}
