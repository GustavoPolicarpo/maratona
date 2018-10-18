// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fatores e Múltiplos
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1056

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

vector <int> adj[205];
int vis[205];
int match[205];

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
	rep(i, 0, n+1){
		adj[i].clear();
		vis[i]=0;
		match[i]=-1;
	}
}

int main()
{
	int T; cin >> T;
	rep(z, 1, T+1){
		
		int N1;
		cin >> N1; int A[N1];
		rep(i, 0, N1)	cin >> A[i];
		
		int N2;	
		cin >> N2; int B[N2];
		rep(i, 0, N2)	cin >> B[i];
		
		tozero(N1+N2+2);
		rep(i, 0, N1)
			rep(j, 0, N2){
				if(A[i]==0&&B[j]==0)
					adj[i].pb(j);
				else if(B[j]==0)
					adj[i].pb(j);
				else if(A[i]!=0&&B[j]%A[i]==0)
					adj[i].pb(j);
				
			}
				
		int mcbm=0;
		
		rep(i, 0, N1){
			rep(j, 0, N1)
				vis[j]=0;
			mcbm+=aug(i);
		}
		cout << "Case " << z << ": " << mcbm << endl;					
	}
				
return (0);
}
