// Author: Gustavo Policarpo
// Name: My T-Shirt Suits Me
// Level: 6
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1362

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

vector <int> adj[300];
int vis[300];
int match[300];

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

void buildadj(int n, string a, string b, int times)
{
	int a1, b1;
	if(a=="XXL")
		a1=1; else if(a=="XL")
			  			a1=2; else if(a=="L")
										a1=3;
	if(a=="M")
		a1=4; else if(a=="S")
			  			a1=5; else if(a=="XS")
										a1=6;
										
	if(b=="XXL")
		b1=1; else if(b=="XL")
			  			b1=2; else if(b=="L")
										b1=3;
	if(b=="M")
		b1=4; else if(b=="S")
			  			b1=5; else if(b=="XS")
										b1=6;	
	
	int m=0;
	rep(i, 0, times){
		adj[n].pb(a1+m);
		adj[n].pb(b1+m);
		m+=6;
	}					
}

int main()
{
	int T; cin >> T;
	while(T--){
		int N, M;
		cin >> N >> M;
		int times=N/6;
		tozero(M+N+1);
		rep(i, 0, M){
			string a, b;
			cin >> a >> b;
			buildadj(i, a, b, times);
		}
		
		int mcbm=0;
		rep(i, 0, M){
			rep(j, 0, M)
				vis[j]=0;
			mcbm+=aug(i);
		}
		
		if(mcbm>=M)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;					
	}
					
return (0);
}

