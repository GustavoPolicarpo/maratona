// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Rato no Labirinto
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1799

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

map <string, int> m;
vector <int> adj[40001];
int vis[40001], in=-1, out=-1, queijo=-1, N, E, k=0;

int bfs(int x, int y)
{
	rep(i, 0, N)
		vis[i]=0;
		
	queue <ii> q;
	q.push(mp(x,0));
	
	while(!q.empty()){
		int x=q.front().F, mov=q.front().S; q.pop();
		if(x==y) return mov;
		vis[x]=1;
		rep(i, 0, adj[x].size()){
			int v=adj[x][i];
			if(vis[v]) continue;
			q.push(mp(v, mov+1));
		}	
	}	
}
int main()
{
	cin >> N >> E;
	
	string a,b;
	rep(i, 0, E){
		cin >> a >> b;
		if(!m.count(a)) m[a]=k++;
		if(!m.count(b)) m[b]=k++;
		if(in==-1){
			if(a=="Entrada") in=m[a];
			else if(b=="Entrada") in=m[b];
		}
		if(out==-1){
			if(a=="Saida") out=m[a];
			else if(b=="Saida") out=m[b];
		}
		if(queijo==-1){
			if(a=="*") queijo=m[a];
			else if(b=="*") queijo=m[b];
		}		
		adj[m[a]].pb(m[b]), adj[m[b]].pb(m[a]);
	}
	int minmov=bfs(in, queijo)+bfs(queijo, out);
	cout << minmov << endl;

return 0;
}
