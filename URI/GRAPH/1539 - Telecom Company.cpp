// Author: Gustavo Policarpo
// Name: Telecom Company
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1539

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
#define ALL(c) c.begin(), c.end() 
#define SORT(c) sort(ALL(c)) 
#define UNIQUE(c) { SORT(c); (c).resize( unique(ALL(c))-c.begin() ); }

#define INF 0x3F3F3F3
#define MAXV 100001

const double EPS = 1e-9;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < double, int > ii;
typedef pair < double, ii > iii;

vector <ii> adj[101];
double dist[101];

struct ponto
{
	int x, y, r;
	
};

double dPT(ponto a, ponto b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int dijkstra(int s, int t, int n)
{
	rep(i, 0, n) dist[i]=INF;

	priority_queue <ii> pq;
	pq.push( mp(dist[s]=0, s));
	
	while(!pq.empty()){
		int u=pq.top().S;
		double d=-pq.top().F;
		pq.pop();
		
		if(d!=dist[u]) continue;
		if(u==t) break;
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].S;
			double c=adj[u][i].F;
			if(dist[v]>dist[u]+c){
				dist[v]=dist[u]+c;
				pq.push(mp(-dist[v], v));
			}
		}
	}
	if(dist[t]==INF || fabs(abs(INF-dist[t]))<EPS) return -1;
	return dist[t];
}

int main()
{
	int N;
	while(cin >> N and N){
		ponto pt[N];
		rep(i, 0, N){
			scanf("%d %d %d", &pt[i].x, &pt[i].y, &pt[i].r);
			adj[i].clear();
		}
		rep(i, 0, N)
			rep(j, 0, N){
				if(i==j) continue;
				double aux=dPT(pt[i], pt[j]);
				if(aux<=pt[i].r)
					adj[i].pb(mp(aux, j));
			}
		int C; cin >> C;
		int a1, a2;
		while(C--){
			scanf("%d %d", &a1, &a2);
			int out=trunc(dijkstra(a1-1, a2-1, N));
			printf("%d\n", out);
		}
		
	}
		
return 0;
}
