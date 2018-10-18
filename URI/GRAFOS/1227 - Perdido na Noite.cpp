// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Perdido na Noite
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1227

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


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


vector <int> adj[101];
int vis[101], yep[101], pai[101];

int mc(int a, int b){
	queue <ii> q;
	memset(vis, 0, sizeof vis);
	memset(yep, 0, sizeof yep);
	memset(pai, 0, sizeof pai);
	q.push(mp(a, 0)); vis[a]=1; int ret=0;
	
	while(!q.empty()){
		int u=q.front().F, t=q.front().S; q.pop();
		if(u==b){
			ret=t;
			break;
		}
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(vis[v]) continue;
			vis[v]=1;
			pai[v]=u;
			q.push(mp(v, t+1));
		}
	}
	
	while(pai[b]){
		yep[b]=1;
		b=pai[b];
	}	yep[a]=1;
	
	return ret;
}

int ma(int a){
	queue <int> q;
	memset(vis, 0, sizeof vis);
	q.push(a); vis[a]=1; 
	
	while(!q.empty()){
		int u=q.front(); q.pop();
		if(yep[u]) return u;
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(vis[v]) continue;
			vis[v]=1;
			q.push(v);
		}
	}
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, A, B, C;
	while(scanf("%d %d %d %d", &N, &A, &B, &C) != EOF){
		int u, v;
		
		rep(i, 1, N+1){
			adj[i].clear();
			yep[i]=pai[i]=0;
		}
		rep(i, 1, N){
			scanf("%d %d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		
		int p=mc(B, C);
		int w=ma(A);
		//cout << w << endl;
		//int lb=mc(w, B);
		int lc=mc(w, C);
		
		//cout << p << " " << lb << " " << lc << '\n';
		printf("%.6lf\n", double(lc)/p);
	}
	
	return 0;
}


