// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Dudu Faz Serviço
// Nível: 2
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1610

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F3F

typedef  long long int ll;
typedef pair < int, int > ii;

vector <int> adj[100001];
int vis[100001]; bool ciclo;

void dfs(int u)
{	
	vis[u]=1;
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(vis[v]==1)
			ciclo=true;
		else if(vis[v]==0)
			dfs(v);
	}
	vis[u]=2;
}

void tozero(int n)
{
	rep(i, 0, n+1){
		adj[i].clear();
		vis[i]=0;
	}
	ciclo=false;
}

int main()
{
	int T; scanf("%d", &T);
	while(T--){
		int N, M;
		scanf("%d %d", &N ,&M);
		tozero(N);
		while(M--){
			int A, B;
			scanf("%d %d", &A, &B);
			adj[A].pb(B);
			//adj[B].pb(A);
		}
		rep(i, 1, N+1)
			if(vis[i]==0)
				dfs(i);
				
		if(ciclo)   cout << "SIM";
		else		cout << "NAO";
					cout << endl;			
	}
return 0;		
}
