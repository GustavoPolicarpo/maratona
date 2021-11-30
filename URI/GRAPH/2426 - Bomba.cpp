// Author: Gustavo Policarpo
// Name: Bomba
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2426

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>


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
#define mod 1000000007 

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int N, E, S, M;
vector <ii> adj[505];
int vis[505][3];

int bfs(){
	queue <ii> q;
	q.push(mp(E, 0)); 
	vis[E][0]=1;
	
	while(!q.empty()){
		int u=q.front().F, t=q.front().S; q.pop();
		
		if(u==S) return t;
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F,
				c=adj[u][i].S;
				
			if(c){
				if(t%3==0 && !vis[v][(t+1)%3]){
					q.push(mp(v, t+1));
					vis[v][(t+1)%3]=1;
				}
			}else{
				if(t%3!=0 && !vis[v][(t+1)%3]){
					q.push(mp(v, t+1));
					vis[v][(t+1)%3]=1;
				}
			}
			
		}
		
	}
	
	return -1;
	
}
int main()
{
	scanf("%d%d%d%d", &N, &E, &S, &M);
	int u, v, c;
	rep(i, 0, M){
		scanf("%d%d%d", &u, &v, &c);
		adj[u].pb(mp(v, c));
	}
	
	int ans = bfs();
	
	ans == -1 ? puts("*") : printf("%d\n", ans);
	
	return 0;
	
}
