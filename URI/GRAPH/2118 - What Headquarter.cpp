// Author: Gustavo Policarpo
// Name: What Headquarter?
// Level: 10
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2118

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

struct ver{
	int u, dst, med, ida, id;
};

ver n[100010];
vector <int> adj[100010];
vector <ver> sedes;


int L, S, Q, A;

bool cmp(ver a, ver b){
	if(a.med!=b.med) return a.med>b.med;
	return a.ida>b.ida;
}

void bfs(ver ori){
	
	//cout << ori.med << " " << ori.ida << "\n";
	queue <ii> q; ii aux;
	aux.F=ori.u, aux.S=ori.dst;
	q.push(aux);
	
	while(!q.empty()){
		int u=q.front().F, c=q.front().S; q.pop();
		
		rep(i, 0, adj[u].size()){
			int v=adj[u][i];
			if(n[v].dst > c+1){
				n[v]=ori, n[v].dst=c+1;
				q.push(mp(v, c+1));
			}
				
		}
		
	}
	
}

const int INF = 0x3f3f3f3f;

int main()
{
	
	scanf("%d %d %d %d", &L, &S, &Q, &A);
	
	rep(i, 1, L+1) n[i].dst=INF, n[i].med=-1, n[i].ida=-1;
	
	int u, v, c;
	rep(i, 0, S){
		scanf("%d %d %d", &u, &v, &c);
		n[u].u=u, n[u].dst=0;
		if(n[u].med > v) continue;
		if(n[u].med == v && n[u].ida >= c) continue;
		n[u].med=v, n[u].ida=c, n[u].id=i+1;
		sedes.pb(n[u]);
	}
	
	while(A--){
		scanf("%d %d", &u, &v);
		adj[u].pb(v),
		adj[v].pb(u);
	}
	
	sort(sedes.begin(), sedes.end(), cmp);
	
	rep(i, 0, sedes.size()) bfs(sedes[i]);
	
	//rep(i, 1, L+1) cout << n[i].u << " " << n[i].dst << '\n';
	
	while(Q--){
		scanf("%d", &u);
		n[u].dst>=INF ? puts("Noic") : printf("%d\n", n[u].id);
	}
	
	return 0;
	
}
