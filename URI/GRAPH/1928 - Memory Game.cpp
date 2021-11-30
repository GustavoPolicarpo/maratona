// Author: Gustavo Policarpo
// Name: Memory Game
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1928

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
const int N = 50050;
int pai[N][22], h[N];
vector <int> adj[N];
int c1[N], c2[N];

void dfs(int u, int last)
{
	pai[u][0]=last;
	rep(i, 1, 22){
		if(pai[u][i-1]==-1) continue;
		pai[u][i]=pai[pai[u][i-1]][i-1];	
	}
	
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(v==last) continue;
		h[v]=h[u]+1;
		dfs(v, u);
	}
	return;
}

void bfs(int u, int last)
{
	queue <ii> q;
	q.push(mp(u, last));
	while(!q.empty()){
		u=q.front().F, last=q.front().S; q.pop();
		pai[u][0]=last;
		rep(i, 1, 22){
			if(pai[u][i-1]==-1) continue;
			pai[u][i]=pai[pai[u][i-1]][i-1];	
		}
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(v==last) continue;
			h[v]=h[u]+1;
			q.push(mp(v, u));
		}
	}
	return ;
}

int LCA(int a, int b)
{

	if(h[a]<h[b]) swap(a, b);
	for(int i=21; i>=0; i--){
		if(pai[a][i]==-1) continue;
		if(h[pai[a][i]]>=h[b]) a=pai[a][i];
	}

	if(a==b) return a;
	for(int i=21; i>=0; i--){
		if(pai[a][i]!=pai[b][i]){
			a=pai[a][i], b=pai[b][i];
		}
	}
	
	return pai[a][0];
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, aux, u, v; scanf("%d", &n);
	rep(i, 1, n+1){
		scanf("%d", &aux);
		if(c1[aux]==0) c1[aux]=i;
		else c2[aux]=i;
	}
	rep(i, 0, n-1){
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	h[1]=0;
	bfs(1, -1);
	ll out=0;
	rep(i, 1, n/2+1){
		u=c1[i], v=c2[i]; aux=LCA(u, v);
		//cout << u << " " << v << " " << aux << endl;
		out+=h[u]+h[v]-2*h[aux];
	}
	printf("%lld\n", out);
	
return 0;
}
