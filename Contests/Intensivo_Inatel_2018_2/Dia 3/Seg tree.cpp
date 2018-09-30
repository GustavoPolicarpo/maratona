#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int N, a[100010], Q;
int tree[4*100010], lazy[4*100010];

void build(int no, int i, int j){
	if(i>j) return;
	if(i==j){
		tree[no] = a[i];
		return;
	}
	int L = no*2, R = no*2+1, mid = (i+j)/2;
	build(L, i, mid);
	build(R, mid+1, j);
	tree[no] = tree[L] + tree[R];
}

void propagate(int no, int i, int j){
	if(!lazy[no]) return;
	tree[no] = tree[no] + (j-i+1) * lazy[no];
	if(i!=j){
		int L = no*2, R = no*2+1;
		lazy[L] += lazy[no];
		lazy[R] += lazy[no];
	}
	lazy[no] = 0;
}

int query(int no, int i, int j, int a, int b){
	propagate(no, i, j);
	if(i>j || i>b || j<a) return 0;
	if(i>=a && j<=b) return tree[no];
	int L = no*2, R = no*2+1, mid = (i+j)/2;
	return query(L, i, mid, a, b) +
			query(R, mid+1, j, a, b);
}

void update(int no, int i, int j, int a, int b, int v){
	propagate(no, i, j);
	if(i>j || i>b || j<a) return;
	if(i>=a && j<=b){
		lazy[no] = v;
		propagate(no, i, j);
		return;
	}
	int L = no*2, R = no*2+1, mid = (i+j)/2;
	update(L, i, mid, a, b, v);
	update(R, mid+1, j, a, b, v);
	tree[no] = tree[L] + tree[R];
}


int main(){
	
	int N; cin >> N;

	rep(i, 0, N) scanf("%d", &a[i]);
	build(1, 0, N-1);
	
	
	return 0;
} 
