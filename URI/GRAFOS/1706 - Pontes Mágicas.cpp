// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pontes Mágicas
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1706

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

typedef pair < int, int > ii;
typedef long long int ll;

char nota[1001];
int vis[1001];
vector <int> adj[1001];

int bfs(int v){
	int cont=0;
	queue <int> q;
	q.push(v);
	
	while(!q.empty()){
		v=q.front(); q.pop();
		if(vis[v]!=1){
			vis[v]=1;
			if(nota[v]=='B')
				cont++;
			rep(i, 0, adj[v].size())
				q.push(adj[v][i]);
		}
	}
	return cont;
}


void tozero(int n)
{
	rep(i, 0, n+1){
		vis[i]=0;
		adj[i].clear();
	}
	
}

int main ()
{
	int N, M;
	while( cin >> N >> M ){
		tozero(N);
		rep(i, 1, N+1)
			cin >> nota[i];
		rep(i, 0, M){
			int x, y;
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		bool did=true;
		int cont;
		rep(i, 1, N+1){
			if(vis[i]==0)
				cont=bfs(i);
			if(cont%2!=0){
				did=false;
				break;
			}		
		}
		if(did)	cout << 'Y';
		else 	cout << 'N';
		cout << endl;	
	}
   
return 0;
}
