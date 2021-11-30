// Author: Gustavo Policarpo
// Name: Chinese Miai
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1821

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned long long int ull;
typedef pair < int, ll > ii;
typedef pair < double, int > iii;

int N, M, match[404], vis[202], mat[202][202];
vector <int> adj[202];

int aug(int u){
	if(vis[u]) return 0;
	vis[u]=1;
	rep(i, 0, adj[u].size()){
		int v=adj[u][i];
		if(match[v]==-1 || aug(match[v])){
			match[v]=u;
			return 1;
		}
	}
	return 0;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int z=1;
	while(scanf("%d %d", &N, &M) and N+M){
		
		rep(i, 0, N){
			adj[i].clear();
			match[i]=-1;
			rep(j, N, N+N)
				mat[i][j]=0;
		}	rep(j, N, N+N)
				match[j]=-1;
		
		int u, v;
		rep(i, 0, M){
			scanf("%d %d", &u, &v);
			u--, v--, v+=N;
			mat[u][v]=1,
			mat[v][u]=1;
		}
		
		rep(i, 0, N)
		rep(j, N, N+N)
			if(!mat[i][j]) 
				adj[i].pb(j);
		
		/*rep(i, 0, N){
			rep(j, 0, adj[i].size())
				cout << adj[i][j] << " ";
			cout << '\n';
		}*/
		
		int mcbm=N;
		rep(i, 0, N){
			rep(j, 0, N+N+1) vis[j]=0;
			mcbm-=aug(i);
		}
		
		//if(z-1) printf("\n");
		printf("Instancia %d\n", z++);
		puts( mcbm==0 ? "possivel" : "impossivel");
		printf("\n");
		
	}
	

return 0;
}
