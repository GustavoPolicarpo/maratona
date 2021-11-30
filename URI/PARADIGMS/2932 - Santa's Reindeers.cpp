// Author: Gustavo Policarpo
// Name: Santa's Reindeers
// Level: 10
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2932

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

int N, M;
vector <iii> edg;
int pset[200020];
int mark[200020];

int findset(int x){
	if(pset[x]!=x) pset[x] = findset(pset[x]);
	return pset[x];
}

void unionset(int x, int y, int c, ll &ans){
	x = findset(x), y = findset(y);
	if(mark[x] && mark[y]) ans+=c;
	else{
		pset[x] = y;
		mark[y]|=mark[x];
	}
}

int main(){
	
	scanf("%d %d", &N, &M);
	
	rep(i, 0, N+2) pset[i] = i, mark[i] = 0;
	
	int u, v, c;
	rep(i, 0, M){
		scanf("%d", &u);
		mark[u] = 1;
	}
	
	rep(i, 0, N-1){
		scanf("%d %d %d", &u, &v, &c);
		edg.pb(iii(c, ii(u, v)));
	}
	
	sort(edg.begin(), edg.end());
	reverse(edg.begin(), edg.end());
	
	ll ans = 0;
	rep(i, 0, edg.size())
		unionset(edg[i].S.F, edg[i].S.S, edg[i].F, ans);
	
	cout << ans << '\n';
			
	return 0;
}
