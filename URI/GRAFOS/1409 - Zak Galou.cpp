// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Zak Galou
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1409

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

struct skill{
	int mana, dano;
};
int M, N, G, K, vis[1001]; ll custo[1001], pd[1001];
vector <int> adj[1001];
vector <int> monster[1001];
skill magia[1001];

void init(int n){
	rep(i, 0, n){
		adj[i].clear();
		monster[i].clear();
		vis[i]=0, custo[i]=INF;
		pd[i]=-1;
	}
	rep(i, n, 1001) pd[i]=-1;
}

int solve(int life){
	
	if(life<=0) return 0;
	ll &p = pd[life];
	if(p!=-1) return p;
	int ret=INF;
	rep(j, 0, M){
		ret=min(ret, solve(life-magia[j].dano)+magia[j].mana);
	}
	return p=ret;
}

ll bfs(){ 
	queue <ii> q;
	int u=1, v; ll c, aux=0;
	rep(i, 0, monster[u].size()) aux+=solve(monster[u][i]);
	q.push(mp(u, aux)); custo[u]=aux;
	while(!q.empty()){
		int u=q.front().F, c=q.front().S; q.pop(); vis[u]=1;
		rep(j, 0, adj[u].size()){
			int v=adj[u][j]; aux=0;
			if(vis[v]) continue;
			rep(i, 0, monster[v].size()) aux+=solve(monster[v][i]);
			if(c+aux<custo[v]){
				custo[v]=c+aux;
				q.push(mp(v, c+aux));
			}
		}	
	}
	return custo[N];
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	while(1){
		scanint(M),scanint(N),scanint(G),scanint(K);
		if(M==0) break;
		init(N+1);
		rep(i, 0, M){
			scanint(magia[i].mana), scanint(magia[i].dano);
		}
		int u, v;
		rep(i, 0, G){
			scanint(u), scanint(v);
			adj[u].pb(v), adj[v].pb(u);
		}
		rep(i, 0, K){
			scanint(u), scanint(v);
			monster[u].pb(v);
		}
		ll out=bfs();
		if(out==INF) printf("-1\n");
		else printf("%d\n", out);
	}

return 0;
}
