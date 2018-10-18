// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Parceiros de Telecomunicação
// Nível: 5
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1344

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

set <int> edg[1010];
int grau[1010], vis[1010];
int N, P, K, cnt;

void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;
	cnt++;
	set <int> :: iterator itt;
	for(itt=edg[u].begin(); itt!=edg[u].end(); itt++){
		int v=*itt;
		if(!vis[v] && grau[v]>=K)
			dfs(v);
	}
	
	return;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	while(1){
		scanint(N), scanint(P), scanint(K);
		
		if(!N) break;
		
		rep(i, 1, N+1){
			edg[i].clear();
			grau[i]=0;
			vis[i]=0;
		}
		
		int u, v;
		while(P--){
			scanint(u), scanint(v);
			edg[u].insert(v);
			edg[v].insert(u);
			grau[u]++, grau[v]++;
		}
		
		priority_queue <ii> pq;
		rep(i, 1, N+1){
			if(grau[i]<K){
				pq.push(mp(-grau[i], i));
				vis[i]=1;
			}
		}
		
		set <int> :: iterator it;
		while(!pq.empty()){
			u=pq.top().S; pq.pop();
			
			for(it=edg[u].begin(); it!=edg[u].end(); it++){
				
				int v=*it;
				if(vis[v]) continue;
				
				it=edg[u].begin();
				edg[u].erase(v); 
				edg[v].erase(u);
				grau[v]--;
				
				if(grau[v]<K){
					pq.push(mp(-grau[v], v));
					vis[v]=1;
				}
				
				if(edg[u].size()==0) break;
			}
		}
		
		int ans=0;
		rep(i, 1, N+1){
			if(!vis[i] && grau[i]>=K){
				cnt=0;
				dfs(i);
				ans=max(ans, cnt);
			}
		}
		
		printf("%d\n", ans);
		
	}


	return 0;
	
}
