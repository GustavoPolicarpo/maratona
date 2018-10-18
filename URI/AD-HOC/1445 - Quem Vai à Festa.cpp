// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Quem Vai à Festa?
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1445

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
}*/
int N, vis[1001];
vector <int> adj[1001];

void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;
	rep(i, 0, adj[u].size()){
		dfs(adj[u][i]);
	}
	return;
}
int main()
{	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int last=0;
	while(scanf("%d", &N) and N){
		int u, v; char nd;
		rep(i, 1, last+1){
			adj[i].clear();
			vis[i]=0;
		}
		rep(i, 0, N){
			scanf(" %c%d%c%d%c", &nd, &u, &nd, &v, &nd);
			adj[u].pb(v);
			adj[v].pb(u);
			last=max(last, max(u, v));
			//cout << u << " " << v << endl;
		}
		int cnt=0;
		dfs(1);
		rep(i, 1, last+1) if(vis[i]) cnt++;
		printf("%d\n", cnt);
	}

return 0;
}



