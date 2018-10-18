// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Todos os Discos Considerados
// Nível: 2
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1669

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

int N1, N2, D, ans, op;
vector <int> adj[100010];
int g[100010], gg[100010];


void answer(){
	
	priority_queue <ii> grau[2];
	rep(i, 1, N1+1) { gg[i]=g[i]; if(gg[i]==0) grau[0].push(mp(g[i], i)); }
	rep(i, N1+1, N1+N2+1){ gg[i]=g[i]; if(gg[i]==0) grau[1].push(mp(g[i], i)); }
	
	priority_queue <iii> pq;
	ans=0; int l=op;
	
	while(!grau[0].empty() || !grau[1].empty()){
		
		ans++;
		while(!grau[l].empty() && grau[l].top().F==0){
			int u=grau[l].top().S; grau[l].pop();
			
			
			rep(i, 0, adj[u].size()){
				int v=adj[u][i];
				gg[v]--;
				
				if(gg[v] > 0 ) continue;
				if(v<=N1) grau[0].push(mp(-gg[v], v));
				if(v> N1) grau[1].push(mp(-gg[v], v));
			}
			
		}
		
		l=1-l;
		
	}
	
	ans++;
	
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(scanf("%d %d %d", &N1, &N2, &D) and N1){
		rep(i, 0, N1+N2+1) adj[i].clear(), g[i]=0;
		
		int x, y, out=INF;
		rep(i, 0, D){
			scanf("%d %d", &x, &y);
			adj[y].pb(x);
			g[x]++;
		}
		
		op=0;
		answer();
		out=min(out, ans);
		
		op=1;
		answer();
		out=min(out, ans);
		
		printf("%d\n", out);
	}
	
	return 0;
	
}
