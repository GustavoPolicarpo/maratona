// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Lero-Lero da Mineira
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2798

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
int vis[26];
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
		printf("%c", out);
		return;
	}
	rep(i, 0, adj[u].size()){
		int v = adj[u][i];
		sol(v);
	}
}

int n, tb; 
char a, b[101], s[100010];
int main(){
	
	scanf("%d", &n);
	
	rep(i, 0, n){
		scanf(" %c %s", &a, b);
		tb = strlen(b);
		if(tb==1 && b[0]==a) continue;
		rep(j, 0, tb){
			if(b[j]-'a'==a-'a') bad[i] = 1;
			adj[a-'a'].pb(b[j]-'a');
		}
	}
	
	scanf("%d %s", &n, s);
	rep(i, 0, n){
		if(vis[s[i]-'a']==0){
			dfs(s[i]-'a');
		}
	}
	
	rep(i, 0, n) sol(s[i]-'a');
	puts("");
	
	return 0;
}
