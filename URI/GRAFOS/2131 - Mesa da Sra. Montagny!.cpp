// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Mesa da Sra. Montagny!
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2131

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

int cor[101];
vector <int> adj[101];
int N, M;

void bfs()
{
	queue<ii> q; ii aux;
	aux.F=0, aux.S=1;
	cor[0]=1;
	q.push(aux);
	while(!q.empty()){
		aux=q.front(); q.pop();
		int u=aux.F, c=aux.S;
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(cor[v]==0){
				cor[v]=c*-1;
				q.push(mp(v, c*-1));
			}
			else if(cor[v]==c){
				printf("nao\n");
				return;
			}
		}
	}
	printf("sim\n");
	return;
}
int main()
{
	int z=1;
	while(scanf("%d %d", &N, &M) !=EOF){
		rep(i, 0, N+1) 
			cor[i]=0, adj[i].clear();
		int u, v;
		rep(i, 0, M){
			scanf("%d %d", &u, &v);
			adj[u-1].pb(v-1);
			adj[v-1].pb(u-1);
		}
		printf("Instancia %d\n", z++);
		bfs();
		printf("\n");
	}
	
	
	
			
return 0;
}
