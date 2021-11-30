// Author: Gustavo Policarpo
// Name: Decode the Strings
// Level: 9
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1644

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
typedef pair<ii, int> iii;

const ll mod = 1e9+7;

int N, M; string s;

#define MAXV 88

int vis[MAXV], circle[MAXV], tam[MAXV], adj[MAXV], ans[MAXV];

void dfs(int u, int t){
	vis[u]=1, tam[u]=t;
	int v=adj[u];
	if(vis[v]==1){
		circle[v]=t-tam[v]+1;
		return;
	}
	if(vis[v]==0) dfs(v, t+1);
	vis[u]=2;
}

void solve(int u, int m, int ini){
	if(circle[u]!=-1) m%=circle[u];
	if(m==0){
		ans[ini]=u;
		return;
	}
	solve(adj[u], m-1, ini);
}

int main(){

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(cin >> N >> M){
		
		if(!N) break;
		
		rep(i, 1, N+1) cin >> adj[i]; cin.ignore(); getline(cin, s); string aux = s;
		
		rep(i, 0, N+2) vis[i]=0, tam[i]=0, circle[i]=-1, ans[i]=i;
		rep(i, 1, N+1) if(vis[i]==0) dfs(i, 0);
		
		
		rep(i, 1, N+1) solve(i, M, i);
		
		rep(i, 1, N+1) aux[ans[i]-1] = s[i-1];
		cout << aux << '\n';
		
	}
	
	return 0;	
}
