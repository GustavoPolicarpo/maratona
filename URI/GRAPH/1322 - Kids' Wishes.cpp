// Author: Gustavo Policarpo
// Name: Kids' Wishes
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1322

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
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int K, W, vis[500001], viz[500001][2], aux;
vector <int> adj[500001];
bool yep, ciclo;

void dfs(int u)
{
	vis[u]=1;
	rep(i, 0, adj[u].size()){
		int v=adj[u][i]; 
		
		if(viz[u][0]==v || viz[u][1]==v) continue;
		else if(viz[u][0]==-1) viz[u][0]=v;
		else if(viz[u][1]==-1) viz[u][1]=v;
		else {
			yep=false;
				return;
		}
		if(viz[v][0]==u || viz[v][1]==u) continue;
		else if (viz[v][0]==-1) viz[v][0]=u;	
		else if(viz[v][1]==-1) viz[v][1]=u;
		else {
			yep=false;
				return;
		}
		if(vis[v]==1){
			ciclo=true;
			return;
		}
	
		dfs(v);	
	}
}
int main()
{
	while(scanf("%d %d", &K, &W) and K+W){
		map <int, int> vol;
		rep(i, 0, min(500001, 2*W+100)){
			adj[i].clear(), vis[i]=0; 
			rep(j, 0, 2)
				viz[i][j]=-1;
		} 
		yep=true, ciclo=false, aux=0;	
		int k=0, a, b;
		rep(i, 0, W){
			scanf("%d %d", &a, &b);
			if(!vol.count(a)) vol[a]=k++;
			if(!vol.count(b)) vol[b]=k++;
			adj[vol[a]].pb(vol[b]);
			adj[vol[b]].pb(vol[a]);
			if(adj[vol[a]].size()>4 || adj[vol[b]].size()>4) yep=false;			
		}
		if(!yep){
			printf("N\n");
			continue;
		}
		
		int el=0;
		rep(i, 0, k){
			if(vis[i]==0){
				el++;
				dfs(i);
			}
		}
		if(yep && ((el==1&&ciclo==true&&k>=K) || ciclo==false)) printf("Y\n");
		else printf("N\n");	
	}
	        
return (0);	
}
