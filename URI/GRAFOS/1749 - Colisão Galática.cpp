// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Colisão Galática
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1749

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

#define INF 0x3F3F3F3F3F3F3F
#define MAXV 100001
#define mod 1000000007
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
typedef pair < int, ii > iii;

void scanint(ll &x)
{
    register ll ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int vis[50500];
vector <int> adj[50500];
vector <ii> in;

int cnt, a;

void dfs(int u, int c){
	if(vis[u]) return;
	vis[u]=1;
	if(c) a++;
	cnt++;
	rep(i, 0, adj[u].size()) 
		dfs(adj[u][i], !c);
}

ll dst(ii a, ii b){
	return ( (a.F - b.F)*(a.F - b.F) + (a.S - b.S)*(a.S - b.S));
}

void bfs(int u, int c){
	queue <ii> q;
	q.push(mp(u, c)); vis[u]=1;
	while(!q.empty()){
		u=q.front().F, c=q.front().S; q.pop();
		if(c) a++; cnt++;
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(!vis[v]){
				vis[v]=1;
				q.push(mp(v, !c));
			}	
		}
	}
	return ;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	ll N; scanint(N) ;ii aux;
	
	rep(i, 0, N){
		scanint(aux.F), scanint(aux.S);
		in.pb(aux);
	}
	
	sort(in.begin(), in.end());
	
	rep(i, 0, N){
		rep(j, i+1, N){
			if(in[i].F+5<in[j].F) break;
			else if(in[i].S+5<in[j].S){
				int p=lower_bound(in.begin()+j, in.end(), ii(in[j].F+1, -INF))-in.begin();
				j=p;
				if(j==N) break;
			}
			else if(in[i].S>in[j].S+5)	{
				int p=lower_bound(in.begin()+j, in.end(), ii(in[j].F, in[i].S-5))-in.begin();
				j=p;
				if(j==N) break;
			}
			if(dst(in[i], in[j])<=25)
				adj[i].pb(j), adj[j].pb(i);
		}
	}
	
	/*rep(i, 0, N){
		cout << i << " : ";
		rep(j, 0, adj[i].size()){
			cout << adj[i][j] << " ";
		}
		cout << endl;
	}*/
	
	int ans=0;
	rep(i, 0, N){
		if(!vis[i]){
			cnt=a=0;
			bfs(i, 0);
			ans+=min(a, cnt-a);
		}
	}
	
	printf("%d\n", ans);
	
return 0;

}
