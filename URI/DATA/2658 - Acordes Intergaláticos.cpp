// Author: Gustavo Policarpo
// Name: Acordes Intergaláticos
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2658

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const ll mod = 1e9+7;


struct use{
	int qt[10];
	int lazy;
};

use tree[400004];

void build(int no, int i, int j){
	if(i==j){
		tree[no].lazy = 0;
		tree[no].qt[1] = 1;
		return;
	}
	int L=no*2, R=L+1, mid=(i+j)/2;
	build(L, i, mid);
	build(R, mid+1, j);
	rep(z, 0, 9) tree[no].qt[z] = tree[L].qt[z]+tree[R].qt[z];
}

void propagate(int no, int i, int j){
	while(tree[no].lazy>=9) tree[no].lazy-=9;
	if(tree[no].lazy){
		use xua = tree[400002];
		rep(z, 0, 9){
			int go = z+tree[no].lazy; if(go>=9) go-=9;
			xua.qt[go] = tree[no].qt[z];
		}
		rep(z, 0, 9) tree[no].qt[z] = xua.qt[z];
		if(i!=j){
			tree[no*2].lazy+=tree[no].lazy;
			tree[no*2+1].lazy+=tree[no].lazy;
		}
		tree[no].lazy=0;
	}
}

void update(int no, int i, int j, int a, int b, int v){
	propagate(no, i, j);
	if(i>j || i>b || j<a) return;
	if(i>=a && j<=b){
		tree[no].lazy += v;
		propagate(no, i, j);
		return;
	}
	int L=no*2, R=L+1, mid=(i+j)/2;
	update(L, i, mid, a, b, v);
	update(R, mid+1, j, a, b, v);
	rep(z, 0, 9) tree[no].qt[z] = tree[L].qt[z]+tree[R].qt[z];
}

use query(int no, int i, int j, int a, int b){
	propagate(no, i, j);
	if(i>b || j<a) return tree[400002];
	if(i>=a && j<=b) return tree[no];
	int L=no*2, R=L+1, mid=(i+j)/2;
	use A=query(L, i, mid, a, b);
	use B=query(R, mid+1, j, a, b);
	use ret = tree[400002];
	rep(z, 0, 9) ret.qt[z] = A.qt[z]+B.qt[z];
	return ret;
}

int ans[400004];
void solve(int no, int i, int j){
	propagate(no, i, j);
	if(i==j) rep(z, 0, 9){
		if(tree[no].qt[z]){
			ans[i] = z;
			return;
		}
	}
	int L=no*2, R=L+1, mid=(i+j)/2;
	solve(L, i, mid);
	solve(R, mid+1, j);
}

int main(){
	
	int N, Q, a, b;
	scanf("%d %d", &N, &Q);
	build(1, 0, N-1);
	while(Q--){
		scanf("%d %d", &a, &b);
		if(a>b) swap(a, b);
		use aux = query(1, 0, N-1, a, b);
		int maior = 0, nota = -1;
		rep(z, 0, 9){
			if(aux.qt[z]>=maior)
				maior = aux.qt[z], nota = z;
		}
		update(1, 0, N-1, a, b, nota);
	}
	solve(1, 0, N-1);
	rep(i, 0, N) printf("%d\n", ans[i]);
	
	return 0;
}
