// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Caixa Dois
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2173

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
#define error 1e-4

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, M;
vector <iii> adj;
int pset[10001];

int findset(int x){
	if(pset[x]!=x)
		pset[x]=findset(pset[x]);
	return pset[x];
}
void unionset(int x, int y){
	x=findset(x), y=findset(y);
	if(x==y) return;
	pset[x]=y;
}

bool sameset(int x, int y){
	return findset(x)==findset(y);
}
int main()
{
	while(1){
		//scanf("%d %d", &N, &M);
		scanint(N), scanint(M);
		if(!N) break; adj.clear();
		
		int u, v, c;
		rep(i, 0, M){
			//scanf("%d %d %d", &u, &v, &c);
			scanint(u), scanint(v), scanint(c);
			adj.pb(mp(c, mp(u, v)));
		}
	
		int minimun=0;
		sort(adj.begin(), adj.end()); rep(i, 1, N+1) pset[i]=i;
		rep(i, 0, adj.size()){
				u=adj[i].S.F,
				v=adj[i].S.S,
				c=adj[i].F;
			if(!sameset(u, v)){
				unionset(u, v);
				minimun+=c;
			}
		}
		
		int maximun=0;
		reverse(adj.begin(), adj.end()); rep(i, 1, N+1) pset[i]=i;
		rep(i, 0, adj.size()){
			int u=adj[i].S.F,
				v=adj[i].S.S,
				c=adj[i].F;
			if(!sameset(u, v)){
				unionset(u, v);
				maximun+=c;
			}
		}
		//cout << maximun << " " << minimun << endl;
		
		printf("%d\n", maximun-minimun);
	}
	
	
return 0;

}

