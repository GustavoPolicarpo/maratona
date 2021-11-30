// Author: Gustavo Policarpo
// Name: Multicampus UFFS
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1908

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

int bfs(int v, int fim, int cost)
{
	queue <ii> q;
	q.push(mp(v, cost));
	while(!q.empty()){
		v=q.front().first;
		cost=q.front().second;
		q.pop();
		if(vis[v]!=1){
			vis[v]=1;
			rep(i, 0, adj[v].size()){
				int w=adj[v][i];
				if(w==fim)
					return cost;
				q.push(mp(w, cost+1));
			}
		}
	}
}

void tozero(int n)
{
	rep(i, 0, n+1){
		adj[i].clear();
		vis[i]=0;
	}
}

int main()
{
	int N, K;
	while(cin >> N >> K){
		tozero(N);
		while(K--){
			int Q; cin >> Q;
			int vi[Q];
			rep(i, 0, Q)
				cin >> vi[i];
			rep(i, 0, Q)
				rep(j, i+1, Q){
						adj[vi[i]].pb(vi[j]);
						adj[vi[j]].pb(vi[i]);	
				}
			}
			int out=bfs(1, N, 1);
			cout << out << endl;	
		}	
		
return (0);	
}
