// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Escalonamento Ótimo
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2403

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

int n, m, grau[50050];
vector <int> adj[50050], out;

void solve(){
	
	priority_queue <int> pq;
	
	rep(i, 0, n){
		if(!grau[i]){
			pq.push(-i);
		}
	}
	
	while(!pq.empty()){
		int u=-pq.top(); pq.pop();
		out.pb(u);
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			grau[v]--;
			if(!grau[v]){
				pq.push(-v);
			}
		}
	}
	
	return;
	
}
int main()
{
	scanint(n), scanint(m);
	int u, v;
	rep(i, 0, m){
		scanint(u), scanint(v);
		adj[u].pb(v);
		grau[v]++;
	}
	
	solve();
	
	if(out.size() == n){
		rep(i, 0, n) printf("%d\n", out[i]);
	}else{
		puts("*");
	}
	
	return 0;
	
}
