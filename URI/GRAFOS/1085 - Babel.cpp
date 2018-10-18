// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Babel
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1085

#include<bits/stdc++.h>
#define gc getchar_unlocked


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
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}
*/
int M, O, D, dist[4001][30];
map <string, int> mapa;
vector <iii> adj[4001];

int dijskatra(){
	memset(dist, INF, sizeof dist);
	priority_queue <iii> pq; 
	rep(i, 0, 30) dist[O][i]=0;
	rep(i, 0, adj[O].size()){
		int v=adj[O][i].F;
		int t=adj[O][i].S.F;
		int cx=adj[O][i].S.S;
		dist[v][cx]=t;
		pq.push(mp(-dist[v][cx], mp(v, cx)));
	}
	while(!pq.empty()){
		int u=pq.top().S.F, c=pq.top().S.S, d=-pq.top().F; pq.pop();
			if(u==D) return d;
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F;
			int t=adj[u][i].S.F;
			int cx=adj[u][i].S.S;
			if(cx==c) continue;
			if(dist[v][cx]<dist[u][c]+t) continue;
			dist[v][cx]=dist[u][c]+t;
			pq.push(mp(-dist[v][cx], mp(v, cx)));
		}
	}
	return INF;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(scanf("%d", &M) and M){
		mapa.clear();
		int cnt=0, tam, u, v; string a, b, c;
		cin >> a >> b; 
		mapa[a]=cnt++, mapa[b]=cnt++;
		O=0, D=1;
		rep(i, 0, M){
			cin >> a >> b >> c;
			tam=c.size();
			if(!mapa.count(a)) mapa[a]=cnt++;
			if(!mapa.count(b)) mapa[b]=cnt++;
			u=mapa[a], v=mapa[b];
			adj[u].pb(mp(v, mp(tam, c[0]-'a')));
			adj[v].pb(mp(u, mp(tam, c[0]-'a')));
		}
		int out=dijskatra();
		if(out==INF) puts("impossivel");
		else printf("%d\n", out);
		rep(i, 0, cnt) adj[i].clear();		
	}

return 0;
}
