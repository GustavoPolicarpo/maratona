// Author: Gustavo Policarpo
// Name: Toll
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2230

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
#define MAXN 100001
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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

vector <int> adj[51], out;
int vis[51];

void bfs(int u, int c){
	queue <ii> q;
	q.push(mp(u, c)); vis[u]=1;
	while(!q.empty()){
		u=q.front().F, c=q.front().S; q.pop();
		if(c==0) return;
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(vis[v]) continue;
			vis[v]=1;
			out.pb(v);
			q.push(mp(v, c-1));
		}
	}
}
int main()
{
	int N, M, L, C, z=1;
	while(scanf("%d %d %d %d", &N, &M, &L, &C) and N+M){
		printf("Teste %d\n", z++);
		rep(i, 1, N+1){
			vis[i]=0;
			adj[i].clear();
		}
		out.clear();
		int u, v;
		rep(i, 0, M){
			scanf("%d %d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		bfs(L, C);
		sort(out.begin(), out.end());
		rep(i, 0, out.size()){
			printf("%d ", out[i]);
		}
		printf("\n\n");
	}
	
	return 0;	
}



