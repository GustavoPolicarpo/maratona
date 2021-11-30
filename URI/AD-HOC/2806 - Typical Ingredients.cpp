// Author: Gustavo Policarpo
// Name: Typical Ingredients
// Level: 10
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2806

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

map<string, int> mapa;
vector <string> ing[1111];
set <string> tip;
vector <int> adj[1111];
int qt[1111], n, Q, yep[1111], grau[1111];

void bfs(){
	queue <int> q;
	rep(i, 0, Q){
		if(!grau[i]){
			q.push(i);
			if(qt[i]>ing[i].size()/2) yep[i] = 1;
		}
	}
	
	while(!q.empty()){
		int u = q.front(); q.pop();
		//cout << u << " " << yep[u] << '\n';
		rep(i, 0, adj[u].size()){
			int v = adj[u][i];
			grau[v]--;
			if(yep[u]) qt[v]++;
			//cout << v << " " << grau[v] << '\n';
			if(!grau[v]){
				if(qt[v] > ing[v].size()/2) yep[v] = 1;
				q.push(v);
			}
		}
	}
}

int main(){
	
	cin >> n; string s;
	
	rep(i, 0, n){
		cin >> s;
		tip.insert(s);
	}
	
	cin >> Q;
	
	rep(i, 0, Q){
		cin >> s; int k; cin >> k;
		mapa[s] = i;
		rep(j, 0, k){
			cin >> s;
			ing[i].pb(s);
		}
	}
	
	rep(i, 0, Q){
		rep(j, 0, ing[i].size()){
			s = ing[i][j];
			if(tip.count(s)) qt[i]++;
			else if(mapa.count(s)) adj[mapa[s]].pb(i), grau[i]++;
		}
	}
	
	bfs();
	
	rep(i, 0, Q){
		
		if(yep[i]) puts("porcao tipica");
		else puts("porcao comum");
	}
	
	

	return 0;
}
