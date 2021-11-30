// Author: Gustavo Policarpo
// Name: Plantation
// Level: 10
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2772

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define pb push_back
#define F first
#define S second

using namespace std;

typedef pair<int, int> ii;

int N, M, K, T;
int tree[400040], die[400040];
vector <ii> lazy[400040];

void propagate(int no, int i, int j){
	if(lazy[no].size()==0) return;
	int fst = lazy[no][0].F, lst = lazy[no][lazy[no].size()-1].S;
	if(tree[no]+T<fst){
		die[no] = 1;
		return;
	}
	rep(k, 1, lazy[no].size()){
		if(lazy[no][k-1].S+T<lazy[no][k].F){
			die[no] = 1;
			return;
		}
	}
	tree[no] = lst;
	if(i!=j){
		lazy[no*2].pb(ii(fst, lst));
		lazy[no*2+1].pb(ii(fst, lst));
	}
	lazy[no].clear();
}

void update(int no, int i, int j, int a, int b, int v){
	propagate(no, i, j);
	if(j<a || i>b || die[no]) return;
	if(i>=a && j<=b){
		lazy[no].pb(ii(v, v));
		propagate(no, i, j);
		return;
	}
	int L = no*2, R = L+1, mid = (i+j)/2;
	update(L, i, mid, a, b, v);
	update(R, mid+1, j, a, b, v);
	die[no] = (bool)(die[L]&&die[R]);
	tree[no] = max(tree[L], tree[R]);
}

vector <int> ans;
void solve(int no, int i, int j, int a, int b){
	propagate(no, i, j);
	if(die[no]) return;
	if(i==j){
		if(tree[no]+T>K)
			ans.pb(i+1);
		return;
	}
	int L = no*2, R = L+1, mid = (i+j)/2;
	solve(L, i, mid, a, b);
	solve(R, mid+1, j, a, b);
}

int main(){
	
	while(scanf("%d %d %d", &N, &K, &T)!=EOF){
		
		rep(i, 0, N*4+4) lazy[i].clear(), tree[i] = 0, die[i] = 0; ans.clear();
		
		int l, r;
		rep(i, 1, K+1){
			scanf("%d %d", &l, &r); l--, r--;
			update(1, 0, N-1, l, r, i);
		}
		
		solve(1, 0, N-1, 0, N-1);
		
		printf("%d", ans.size());
		rep(i, 0, ans.size())
			printf(" %d", ans[i]);
		printf("\n");
		
	}
	
    return 0;
}
