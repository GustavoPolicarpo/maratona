// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Decodificando o Texto
// Nível: 6
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2671

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


int N, pointer;
string text, out;

vector <int> adj[10001];
char val[10001];

void build(){
	queue <int> q; q.push(1); int cnt = 1;
	while(!q.empty()){
		int u = q.front(), v; q.pop();
		
		v = u*2, cnt++;
		if(cnt>N) break;
		adj[u].pb(v), q.push(v);
		
		v = u*2+1, cnt++;
		if(cnt>N) break;
		adj[u].pb(v), q.push(v);
	}
}

void dfs(int u){
	if(adj[u].size()) dfs(adj[u][0]);
	if(pointer<text.size()) val[u] = text[pointer++];
	if(adj[u].size()>1) dfs(adj[u][1]);
}

void bfs(){
	queue <int> q; q.push(1);
	while(!q.empty()){
		int u = q.front(); q.pop();
		out.pb(val[u]);
		rep(i, 0, adj[u].size()){
			int v = adj[u][i];
			q.push(v);
		}
	}
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	
	while(cin >> N){
		if(!N) break;
		
		getline(cin, text); getline(cin, text);
		N = text.size();
		
		rep(i, 0, N+N+2) adj[i].clear();
		build(); pointer = 0; dfs(1);
		out.clear(); bfs();
		
		cout << out << '\n';
	}
	
	return 0;
	
}
