// Author: Gustavo Policarpo
// Name: Max, the Mad
// Level: 8
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1529

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

#define INF 0x3F3F3F3F3
#define MAXV 100001

#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int N, M, T, custo[12];
vector <ii> adj[12];
map <ii, int> vis;

int solve(){
	priority_queue	<iii> pq;
	pq.push(mp(0, mp(T, 1))); vis[mp(1, T)]=0;
	
	while(!pq.empty()){
		int u=pq.top().S.S, c=-pq.top().F, t=pq.top().S.F; pq.pop();
		//cout << u << " " << c << " " << t << endl;
		if(u==N) return c;
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F, tt=adj[u][i].S;
			if(tt>t) continue;
			rep(j, 0, T-t+tt+1){
				int cc=custo[v]*j, ca=t-tt+j;
				if(vis.count(mp(v, ca)) && vis[mp(v, ca)]<=c+cc) continue;
				vis[mp(v, ca)]=c+cc;
				pq.push(mp(-(c+cc), mp(ca, v)));
			}	
		}
	}
	return -1;
}
int main()
{
	while(scanf("%d %d %d", &N, &M, &T) and N){
	
		rep(i, 1, N+1) adj[i].clear();
		vis.clear();
		
		int u, v, c;
		rep(i, 0, M){
			scanf("%d %d %d", &u, &v, &c);
			if(c<=T)
				adj[u].pb(mp(v, c)), adj[v].pb(mp(u, c));
		}
		rep(i, 1, N+1) scanf("%d", &custo[i]);
		
		printf("%d\n", solve());
	}
    
    
return 0;

}
