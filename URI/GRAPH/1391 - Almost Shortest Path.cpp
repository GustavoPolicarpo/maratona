// Author: Gustavo Policarpo
// Name: Almost Shortest Path
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1391

#define gc getchar_unlocked
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

#define INF 0x3f3f3f3f
#define MAXV 100001

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ii, vector <ii> > iii;

int N, M, S, D; 
vector <ii> adj[501], limp;
int dist[501], mat[501][501];

struct qq{
	int u, c;
	vector <ii> r;
	
	qq() {}

	bool operator() (qq a,  qq b){
		if(a.c<b.c) return false;
		if(a.c>b.c) return true;
	}
};
int dij(){
	priority_queue <qq, vector <qq> , qq> pq; qq use;
	use.u=S, use.c=0, use.r.clear();
	pq.push(use); dist[S]=0;
	while(!pq.empty()){
		use=pq.top(); pq.pop();
		int u=use.u, w=use.c; vector <ii> r=use.r;
		//cout << u << " " << w << endl;
		if(dist[u]<w) continue;
		if(u==D){
			//cout << "distancia   " << dist[u] << endl;
			rep(i, 0, r.size()){
				//cout << "cheguei " << " " << r[i].F << " " << r[i].S << endl;
				limp.pb(r[i]);
			}
			continue;
		}
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F, 	
				c=adj[u][i].S;
			if(mat[u][v]==1 || dist[v]<dist[u]+c) continue;
			dist[v]=dist[u]+c;
			r.pb(mp(u, v));
			use.u=v, use.c=dist[v], use.r=r;
			pq.push(use);
			r.pop_back();
		}
	}
	return dist[D];
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    while(scanf("%d %d", &N, &M) and N){
    	rep(i, 0, N){
    		adj[i].clear();
    		dist[i]=INF;
    		rep(j, 0, N) mat[i][j]=0;
		} limp.clear();
		scanf("%d %d", &S, &D);
		int u, v, c;
		rep(i, 0, M){
			scanf("%d %d %d", &u, &v, &c);
			adj[u].pb(mp(v, c));
		}
		int minimunpath=dij();
		if(minimunpath>=INF){
			printf("-1\n");
			continue;
		} int ans=-1;
		while(1){
			memset(dist, INF, sizeof dist);
			rep(i, 0, limp.size()) mat[limp[i].F][limp[i].S]=1;
			int quasemenor=dij();
			//cout << minimunpath << " " << quasemenor << endl;
			if(quasemenor!=minimunpath || quasemenor==-1){
				ans=quasemenor;
				break;
			}
		}
		if(ans>=INF) printf("-1\n");
		else printf("%d\n", ans);
	}
    
    
return 0;
}
