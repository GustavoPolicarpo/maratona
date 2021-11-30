// Author: Gustavo Policarpo
// Name: I Hate SPAM, But Some Peo...
// Level: 4
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1317

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define F first
#define S second
#define pb push_back

typedef long long int ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const int MAX=1000010;

vector <int> adj[22];
vector <string> ans[22];
string vs[3];
int vis[22];

void dfs(int u, int a, int b){
	
	if(vis[u]) return;
	vis[u]=1;
	
	int tam=adj[u].size();
	if(tam<a) ans[u].pb(vs[0]);
	else if(tam<b) ans[u].pb(vs[1]);
	else ans[u].pb(vs[2]);
	
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(vis[v]) continue;
		dfs(v, a, b);
	}
	
	return;
	
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int N;
	
	while(scanf("%d", &N) and N){
		
		rep(i, 1, N+1){
			adj[i].clear();
			ans[i].clear();
		}
		int u, a, b; string s;
		rep(i, 1, N+1) while(scanf("%d", &u) and u) adj[i].pb(u);
		
		while(scanf("%d", &u) and u){
			scanf("%d %d", &a, &b); cin >> vs[0] >> vs[1] >> vs[2];
			memset(vis, 0, sizeof vis);
			dfs(u, a, b);
			rep(i, 1, N+1){
				if(!vis[i]){
					ans[i].pb(vs[0]);
				}
			}
		}
		
		rep(i, 1, N+1){
			cin >> s;
			cout << s << ": ";
			rep(j, 0, ans[i].size()) cout << ans[i][j] << " ";
			cout << '\n';
		}
	}
	
	return 0;
	
}
