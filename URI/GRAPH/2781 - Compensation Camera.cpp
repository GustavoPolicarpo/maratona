// Author: Gustavo Policarpo
// Name: Compensation Camera
// Level: 5
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2781

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int n, m;
vector <ii> adj[1010];
int out[1010], in[1010], dif[1010];

int main(){
	

	scanf("%d %d", &m, &n);
	int u, c, v, total = 0, latot = 0;
	rep(i, 0, m){
		scanf("%d %d %d", &u, &c, &v);
		adj[u].pb(ii(v, c));
		out[u]+=c;
		in[v]+=c;
		total+=c;
	}
	
	rep(i, 1, n+1){
		dif[i] = in[i]-out[i];
		latot += abs(dif[i]);
	}	latot/=2;
	
	if(latot!=total){
		puts("S");
		cout << latot << '\n';
	}else{
		puts("N");
		cout << latot << '\n';
	}
	
	
	return 0;
}
