// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Culpado
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1521

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

vector <int> adj[55];

void dfs(int u)
{
	if(adj[u][0]==u){
		printf("%d\n", u);
		return;
	}
	dfs(adj[u][0]);
}
int main()
{
	int N; 
	while(scanf("%d", &N) and N){ int aux;
		rep(i, 1, N+1){
			scanf("%d", &aux); adj[i].clear();
			adj[i].pb(aux);
		}
		int ini; scanf("%d", &ini);
		dfs(ini);
	}

return 0;
}


