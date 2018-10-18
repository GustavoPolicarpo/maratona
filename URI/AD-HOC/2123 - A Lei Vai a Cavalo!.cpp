// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Lei Vai a Cavalo!
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2123

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
typedef pair < double, int > iii;
using namespace std;

void scanint(int &x)
{
    register int c = gc();
    x = 0;
    int neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

vector <int> adj[1000];
int match[20200];
int vis[1000], vv[1000];

int aug(int v)
{
	if(vis[v]==1) return 0;
	vis[v]=1;
	rep(j, 0, adj[v].size()){
		int r=adj[v][j];
		if(match[r]==-1 || aug(match[r])){
			match[r]=v;
			return 1;
		}
	}
	return 0;
}

int main()
{
	int n, m, k, z=1;
	while(scanf("%d %d %d", &n, &m, &k) !=EOF){
		memset(match, -1, sizeof match);
		rep(i, 0, m+1) adj[i].clear();
		
		rep(i, 0, n) scanf("%d", &vv[i]);
		int s, c;
		rep(i, 0, k){
			scanint(c), scanint(s);
			int aux=c*100+1;
			rep(j, 0, vv[c-1])
				adj[s-1].pb(aux++);
		}
		
		int mcbm=0;
		
		rep(i, 0, m){
			rep(j, 0, m+1)
				vis[j]=0;
			mcbm+=aug(i);
		}
		printf("Instancia %d\n%d\n\n", z++,mcbm);
	}
	
}
