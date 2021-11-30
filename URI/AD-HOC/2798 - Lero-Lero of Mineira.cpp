// Author: Gustavo Policarpo
// Name: Lero-Lero of Mineira
// Level: 10
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2798

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


vector <int> adj[26];
string s; int vis[26];
int bad[26];

void dfs(int u){
	if(bad[u]){
		puts("-1");
		exit(0);
	}
	vis[u] = 1;
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		if(vis[v]==1){
			puts("-1");
			exit(0);
		}
		if(!vis[v]){
			dfs(v);
		}
	}
	vis[u] = 2;
}

void sol(int u){
	if(!adj[u].size()){
		char out = u+'a';
		cout << out;
		return;
	}
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		sol(v);
	}
}

int main(){
	
	int n; cin >> n;
	string a, b;
	
	rep(i, 0, n){
		cin >> a >> b;
		if(b.size()==1 && b[0]==a[0]) continue;
		rep(j, 0, b.size()){
			if(b[j]-'a'==a[0]-'a') bad[i] = 1;
			adj[a[0]-'a'].pb(b[j]-'a');
		}
	}
	
	cin >> n >> s;
	rep(i, 0, s.size()){
		if(vis[s[i]-'a']==0){
			dfs(s[i]-'a');
		}
	}
	rep(i, 0, s.size()) sol(s[i]-'a');
	puts("");
	
	return 0;
}
