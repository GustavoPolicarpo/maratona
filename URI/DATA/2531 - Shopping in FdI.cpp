// Author: Gustavo Policarpo
// Name: Shopping in FdI
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2531

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ll, ii > iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;

ii tree[400040];
int v[100010];

void build(int no, int i, int j){
	if(i==j){
		tree[no]=mp(v[i], v[i]);
		return;
	}
	int mid=(i+j)/2, L=no*2, R=L+1;
	build(L, i, mid);
	build(R, mid+1, j);
	tree[no].F=max(tree[L].F, tree[R].F);
	tree[no].S=min(tree[L].S, tree[R].S);
}

void update(int no, int i, int j, int a, int v){
	if(i>a || j<a || i>j) return;
	if(i==j && i==a){
		tree[no]=mp(v, v);
		return;
	}
	int mid=(i+j)/2, L=no*2, R=L+1;
	update(L, i, mid, a, v);
	update(R, mid+1, j, a, v);
	tree[no].F=max(tree[L].F, tree[R].F);
	tree[no].S=min(tree[L].S, tree[R].S);
}

ii query(int no, int i, int j, int a, int b){
	if(i>b || j<a || i>j) return mp(0, INF);
	if(i>=a && j<=b) return tree[no];
	int mid=(i+j)/2, L=no*2, R=L+1;
	ii A=query(L, i, mid, a, b);
	ii B=query(R, mid+1, j, a, b);
	return mp(max(A.F, B.F), min(A.S, B.S));
}
int main(){
	
	int n, q;
	
	while(scanf("%d", &n)!=EOF){
		
		rep(i, 0, n) scanf("%d", &v[i]);
		
		build(1, 0, n);
		
		scanf("%d", &q);
		
		int op, a, b;
		while(q--){
			scanf("%d %d %d", &op, &a, &b);
			if(op==1){
				update(1, 0, n, a-1, b);
			}else{
				ii ans=query(1, 0, n, a-1, b-1);
				printf("%d\n", abs(ans.F-ans.S));
			}
		}
		
	}
	
	return 0;
	
}
