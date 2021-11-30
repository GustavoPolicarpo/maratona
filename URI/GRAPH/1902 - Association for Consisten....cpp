// Author: Gustavo Policarpo
// Name: Association for Consisten...
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1902

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;

#define INF 0x3f3f3f3f
const int mod=1e9+7;


map<string, int> mapa;
vector <int> adj[200020];
int vis[200020], ans;

void dfs(int u){
	
	if(vis[u]) return;
	
	vis[u]=1;
	
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(vis[v]==1){
			ans++;
		}else{
			dfs(v);
		}
	}
	
	vis[u]=2;
	
	return;
	
}


int main(){
	
	char a[12], b[12]; int cnt=0;
	
	while(scanf("%s %s", a, b) !=EOF){
		
		//if(a[0]=='$') break;
		
		if(!mapa.count(a)) mapa[a]=cnt++;
		if(!mapa.count(b)) mapa[b]=cnt++;
		adj[mapa[a]].pb(mapa[b]);
		
		
		
	}
	
	ans=0;
		
	rep(i, 0, cnt){
		if(!vis[i])
			dfs(i);
	}
	
	printf("%d\n", ans);
	
	return 0;
	
}
