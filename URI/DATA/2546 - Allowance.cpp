// Author: Gustavo Policarpo
// Name: Allowance
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2546

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;

int N, Q;
int v[100010], lazy[400040];
ii tree[400040];

void build(int no, int i, int j){

	if(i==j){
		tree[no]=mp(v[i], i);
		return;
	}
	
	int L=no*2, R=L+1, mid=(i+j)/2;
	build(L, i, mid);
	build(R, mid+1, j);
	
	lazy[L]=0, 	lazy[R]=0;
	if(tree[L].F>=tree[R].F) tree[no]=tree[L];
	else tree[no]=tree[R];

}

void propagate(int no, int i, int j){
	if(lazy[no]){
		tree[no].F+=lazy[no];
		if(i!=j){
			lazy[no*2]+=lazy[no];
			lazy[no*2+1]+=lazy[no];
		}
		lazy[no]=0;
	}
	return;
}


void update(int no, int i, int j, int a, int b, int v){
	
	propagate(no, i, j);
	if(i>b || j<a) return;
	
	if(i>=a && j<=b){
		tree[no].F+=v;
		if(i!=j){
			lazy[no*2]+=v;
			lazy[no*2+1]+=v;
		}
		return;
	}
	
	int L=no*2, R=L+1, mid=(i+j)/2;
	update(L, i, mid, a, b, v);
	update(R, mid+1, j, a, b, v);

	if(tree[L].F>=tree[R].F) tree[no]=tree[L];
	else tree[no]=tree[R];

}

ii query(int no, int i, int j, int a, int b){
	
	propagate(no, i, j);
	if(i>b || j<a) return ii(0, 0);
	if(i>=a && j<=b) return tree[no];
	
	int L=no*2, R=L+1, mid=(i+j)/2;
	ii A=query(L, i, mid, a, b);
	ii B=query(R, mid+1, j, a, b);
	
	if(A.F>=B.F) return A;
	return B;
}


int main(){
	
	while(scanf("%d %d", &N, &Q)!=EOF){
	
		rep(i, 1, N+1) scanf("%d", &v[i]);
		
		build(1, 1, N);
		
		char op; int a, b, v;
		
		while(Q--){
			scanf(" %c %d %d", &op, &a, &b);
			if(op=='A'){
				scanf("%d", &v);
				update(1, 1, N, a, b, v);
			}else{
				ii ans=query(1, 1, N, a, b);
				printf("%d\n", ans.S);
			}
		
		}
	
	}

	return 0;
	
}
