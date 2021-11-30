// Author: Gustavo Policarpo
// Name: Contests in Sequence
// Level: 3
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1878

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef pair < int, int > ii;
typedef pair < ii, int > iii;
typedef long long int ll;

const int INF = 0x3f3f3f3f;

int N, M, v[5], yep;

int vis[3][12];

void dfs(int u, ll sa, ll sb, int p){
	
	if(u==N){
		if(sa==sb){
			yep=0;
			return;
		}
		return;
	}
	if(p==1){
		rep(i, 1, M+1){
			if(vis[u][i]) continue;
			vis[u][i]=1;
			dfs(u+1, sa, sb+ll(v[u])*i, 0);
			vis[u][i]=0;
		}
	}else{
		rep(i, 1, M+1){
			if(vis[u][i]) continue;
			vis[u][i]=1;
			dfs(u, sa+ll(v[u])*i, sb, 1);
			vis[u][i]=0;
		}
	}
	return;
}

bool solve(){
	
	yep=1; memset(vis, 0, sizeof vis);
	rep(i, 1, M+1){
		vis[0][i]=1;
		dfs(0, ll(v[0])*i, 0, 1);
		vis[0][i]=0;
		if(!yep) break;
	}
	return yep? true: false;
}

int main(){
	
	while(scanf("%d %d", &N, &M)!=EOF){
		rep(i, 0, N) scanf("%d", &v[i]);
		solve() ? puts("Lucky Denis!") : puts("Try again later, Denis...");
	}
	
	return 0;
	
}
