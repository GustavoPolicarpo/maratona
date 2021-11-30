// Author: Gustavo Policarpo
// Name: Uiquipédia
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2331

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
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;


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


vector <int> adj[2020];
int vis[2020];

int solve(int a, int b){
	queue <ii> q;
	q.push(mp(a, 0)); vis[a]=1;
	while(!q.empty()){
		int u=q.front().F, c=q.front().S; q.pop();
		if(u==b) return c;
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(vis[v]) continue;
			vis[v]=1;
			q.push(mp(v, c+1));
		}
	}
}
int main ()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, cnt=0; cin >> N;
	map<string, int> mapa;
	vector <string> in; string a, b;
	while(N--){
		cin >> a >> b;
		if(!mapa.count(a)) mapa[a]=cnt++, in.pb(a);
		if(!mapa.count(b)) mapa[b]=cnt++, in.pb(b);
		adj[mapa[a]].pb(mapa[b]);
	}
	
	sort(in.begin(), in.end());
	
	for(int i=0; i<in.size(); i++){
		if(i>0)
			adj[mapa[in[i]]].pb(mapa[in[i-1]]);
		if(i<in.size()-1)
			adj[mapa[in[i]]].pb(mapa[in[i+1]]);
	}
	
	cin >> a >> b;
	printf("%d\n", solve(mapa[a], mapa[b]));
	
	
  
  return 0;
}
