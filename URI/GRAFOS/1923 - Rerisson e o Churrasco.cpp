// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Rerisson e o Churrasco
// Nível: 3
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1923

#include<bits/stdc++.h>
#define gc getchar_unlocked


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
#define mod 1300031
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, int > ii;
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

int N, G, vis[10001][501];
vector <int> adj[10001];
vector <string> out;
set <string> jaja;
map<string, int> go;
map<int, string> back;

void dfs(int u, int g){
	if(vis[u][g]) return;
	vis[u][g]=1; out.pb(back[u]);
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(g-1<0) continue;
		dfs(v, g-1);
	}
	return;
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d %d", &N, &G);
	go["Rerisson"]=0; int cnt=1; string u, v;
	back[0]="Rerisson";
	rep(i, 0, N){
		cin >> u >> v;
		if(!go.count(u)) go[u]=cnt++;	
		if(!go.count(v)) go[v]=cnt++;
		back[go[u]]=u, back[go[v]]=v;
		adj[go[u]].pb(go[v]), adj[go[v]].pb(go[u]);
	}
	dfs(0, G);
	int ans=0;
	sort(out.begin(), out.end());
	jaja.insert("Rerisson");
	vector <string> outout;
	rep(i, 0, out.size()){
		if(jaja.count(out[i])) continue;
		outout.pb(out[i]); ans++;
		jaja.insert(out[i]);
	}
	cout << ans << endl;
	rep(i, 0, outout.size()){
		cout << outout[i] << endl;
	}
	
return 0;	
}
