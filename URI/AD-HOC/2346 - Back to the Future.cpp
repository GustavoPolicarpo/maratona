// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Back to the Future
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2346

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

int g[100010], vis[100010], n, m, A, B;
struct cmp{
	bool operator () ( int a, int b){
		if(g[a]!=g[b]) return g[a] < g[b];
		return a < b;
	}
};

set <int, cmp> st;

vector <int> adj[100010];

int solve(){
	
	rep(i, 1, n+1) g[i]=adj[i].size(), st.insert(i);
	set <int, cmp>::iterator it;
	
	while(1){
		if(st.empty()) break;
		it=st.begin();
		int u=*it;
		
		if(g[u] < A){
			st.erase(u), vis[u]=1;
			rep(i, 0, adj[u].size()){
				int v=adj[u][i];
				if(vis[v]) continue;
				st.erase(v);
				g[v]--;
				st.insert(v);
			}
		}
		else break;
	}
	
	
	while(1){
		if(st.empty()) break;
		it=st.end(); it--;
		int u=*it;
		/*cout << '\n';
		for(it=st.begin(); it!=st.end(); it++)
			cout << *it << " " << g[*it] << '\n';
		cout << '\n' << u << " " << g[u] << " " << st.size() << '\n';*/
		if(st.size()-g[u]-1 < B){
			st.erase(u), vis[u]=1;
			rep(i, 0, adj[u].size()){
				int v=adj[u][i];
				if(vis[v]) continue;
				st.erase(v);
				g[v]--;
				st.insert(v);
			}
		}
		else break;
	}
	
	return st.size();
	
}
int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d %d %d %d", &n, &m, &A, &B);
	int u, v;
	rep(i, 0, m){
		scanf("%d %d", &u, &v);
		adj[u].pb(v), adj[v].pb(u);
	}
	
	printf("%d\n", solve());
	
	return 0;
	
}
