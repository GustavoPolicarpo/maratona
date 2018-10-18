// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A aventura de Super Mario
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1423

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

int vis[101][505][11][2];
vector <ii> adj[101];
int A, B, M, L, K;

struct use{
	int tempo, u, k, l, last;
	bool operator () (use a, use b){
		if(a.tempo < b.tempo) return false;
		if(a.tempo > b.tempo) return true;
		
		if(a.k > b.k) return false;
		if(a.k < b.k) return true;
		
		if(a.l > b.l) return false;
		if(a.l < b.l) return true;
		
		if(a.last > b.last) return false;
		if(a.last < b.last) return true;
	}
};

int solve(){
	priority_queue <use, vector <use>, use> pq;
	vis[A+B][L][K][1]=0; use aux;
	aux.u=A+B, aux.l=L, aux.k=K, aux.last=1, aux.tempo=0;
	pq.push(aux);
	
	while(!pq.empty()){
		aux=pq.top(); pq.pop();
		int u=aux.u, l=aux.l, k=aux.k, last=aux.last, tempo=aux.tempo;
		
	//	cout << u << " " << tempo << '\n';
		if(u==1) return tempo;
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F, 
				c=adj[u][i].S;
			use go;
			if(l!=L){
				if(last==0 && l>=c){
					go.u=v, go.l=l-c, go.k=k, go.last=(v<=A?0:1), go.tempo=tempo;
					if(vis[go.u][go.l][go.k][go.last] <= go.tempo) continue;
					vis[go.u][go.l][go.k][go.last] = go.tempo;
					pq.push(go);
				}
				else{
					if(k-1 && L>=c){
						go.u=v, go.l=L-c, go.k=k-1, go.last=(v<=A?0:1), go.tempo=tempo;
						if(vis[go.u][go.l][go.k][go.last] <= go.tempo) continue;
						vis[go.u][go.l][go.k][go.last] = go.tempo;
						pq.push(go);
					}
					go.u=v, go.l=L, go.k=k-1, go.last=(v<=A?0:1), go.tempo=tempo+c;
					if(vis[go.u][go.l][go.k][go.last] <= go.tempo) continue;
					vis[go.u][go.l][go.k][go.last] = go.tempo;
					pq.push(go);
				}
			}
			else{
				if(k && L>=c){
					go.u=v, go.l=L-c, go.k=k, go.last=(v<=A?0:1), go.tempo=tempo;
					if(vis[go.u][go.l][go.k][go.last] <= go.tempo) continue;
					vis[go.u][go.l][go.k][go.last] = go.tempo;
					pq.push(go);
				}
				go.u=v, go.l=L, go.k=k, go.last=(v<=A?0:1), go.tempo=tempo+c;
				if(vis[go.u][go.l][go.k][go.last] <= go.tempo) continue;
				vis[go.u][go.l][go.k][go.last] = go.tempo;
				pq.push(go);
			}
		}
	}
	
	return -1;
	
}

int main()
{
	int T; cin >> T;
	while(T--){
		scanf("%d %d %d %d %d", &A, &B, &M, &L, &K);
		rep(i, 1, A+B+2){
			adj[i].clear();
			rep(j, 0, L+1)
			rep(k, 0, K+1)
			rep(l, 0, 2)
				vis[i][j][k][l]=INF;
		}
		int u, v, c;
		while(M--){
			scanf("%d%d%d", &u, &v, &c);
			adj[u].pb(mp(v, c));
			adj[v].pb(mp(u, c));
		}
		printf("%d\n", solve());
	}
	
	return 0;
	
}
