// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Anacrônico?
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1813

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

vector <iii> adj[101];

ii dijsktra(int source, int sink, int tempo){
	vector <ii> vis[101];
	priority_queue <iii> pq;
	pq.push(mp(0, mp(0, source))); 
	
	while(!pq.empty()){
		int u=pq.top().S.S, c=-pq.top().F, t=-pq.top().S.F; pq.pop();
		//cout << u << "\n";
		if(u==sink) return mp(c, t);
		
		bool yep=true;
		rep(i, 0, vis[u].size()){
			ii aux=vis[u][i];
			if(aux.F <= c && aux.S <=t){
				yep=false;
				break;
			}
		}
		if(!yep) continue;
		vis[source].pb(mp(0, 0));
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F, 
				cc=adj[u][i].S.F, 
				tt=adj[u][i].S.S;
			if(tt+t > tempo) continue;
			pq.push(mp(-(cc+c), mp(-(tt+t), v)));
		}
	}
	
	return mp(INF, INF);
}
int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int n, m, q, z=1;
	while(scanf("%d %d", &n, &m) and n+m){
		rep(i, 1, n+1) adj[i].clear();
		
		int u, v, c, t;
		while(m--){
			scanf("%d %d %d %d", &u, &v, &c, &t);
			adj[u].pb(mp(v, mp(c, t)));
		}
		
		scanf("%d", &q);
		//if(z-1) printf("\n");
		printf("Instancia %d\n", z++);
		while(q--){
			scanf("%d %d %d", &u, &v, &t);
			ii ans=dijsktra(u, v, t);
			if(ans.S >= INF) puts("Impossivel");
			else printf("Possivel - %d km, %d min\n", ans.F, ans.S);
		}
		printf("\n");
		
	}

	return 0;
	
}
