// Author: Gustavo Policarpo
// Name: Attacking Rooks
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1490

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;

vector <int> adj[100001];
int vis[100001];
int match[100001];
int pc[100001];

int aug(int v)
{
	if(vis[v]==1) return 0;
	vis[v]=1;
	rep(i, 0, adj[v].size()){
		int u=adj[v][i];
		if(match[u]==-1 || aug(match[u])){
			match[u]=v;
			return 1;
		}
	}
	return 0;
}

void tozero(int n)
{
	rep(i, 0, 100000){
		adj[i].clear();
		//vis[i]=0;
	//	match[i]=-1;
	//	pc[i]=0;
	}
}


int main()
{
	int N;
	while(cin >> N){
		char M[N][N];
		
		tozero(N);
		memset(vis, 0, sizeof(vis));
		memset(match, -1, sizeof(match));
		memset(pc, 0, sizeof(pc));
		
		rep(i, 0, N)
			rep(j, 0, N)
				cin >> M[i][j];			
						
		int l=0;	
		rep(i, 0, N){
			rep(j, 0, N){
				if(M[i][j]=='X'){
					l++;
					pc[j]+=N;
				}
				else
					adj[i+l].pb(j+pc[j]);
			}
		}
			
		int mcbm=0;
		
		rep(i, 0, N+l){
			rep(j, 0, N+l)
				vis[j]=0;
			mcbm+=aug(i);
		}
		cout << mcbm << endl;
	}
							
return (0);
}
