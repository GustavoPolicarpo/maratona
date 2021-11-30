// Author: Gustavo Policarpo
// Name: Galactic Taxes
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2011

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
#define error 1e-14

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef pair <double, int> di;

const ll LINF = ll(1)<<60;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

int N, M;
vector <iii> adj[1010];
double dist[1010];

double custo(int u, int i, double t){
	int a=adj[u][i].S.F, b=adj[u][i].S.S;
	return t*a+b;
}
double solve(double t){
	rep(i, 1, N+1) dist[i]=LINF;
	
	priority_queue <di> pq;
	pq.push(mp(0.0, 1)); dist[1]=0.0;
	
	while(!pq.empty()){
		int u = pq.top().S; double c=-pq.top().F; pq.pop();
		if(u==N) return c;
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F;
			double cc=custo(u, i, t);
			
			if(dist[v]<=dist[u]+cc) continue;
			dist[v]=dist[u]+cc;
			pq.push(mp(-dist[v], v));
		}
	}
}

int main ()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d %d", &N, &M);
	int u, v, a, b;
	rep(i, 0, M){
		scanf("%d %d %d %d", &u, &v, &a, &b);
		adj[u].pb(mp(v, mp(a, b)));
		adj[v].pb(mp(u, mp(a, b)));
	}
	
	double ini=0.0, fim=24.0*60.0+error, u1=(ini+fim)/2.0, u2=(u1+fim+error)/2.0, ans=0.0; int cont=111;
	while(cont--){
		//cout << ini << " "	 << u1 << " " << u2 << " " << fim << endl;
		double a1=solve(u1), a2=solve(u2);
		if(a1<=a2){
			ini=u1, fim=fim;
			u1=(ini+fim+error)/2.0, u2=(u1+fim+error)/2.0, ans=max(ans, a2);
		}
		else{
			ini=ini, fim=u2;
			u1=(ini+fim+error)/2.0, u2=(u1+fim+error)/2.0, ans=max(ans, a1);
		}
	}
	
	printf("%.5lf\n", ans);
	
  
  return 0;
}
