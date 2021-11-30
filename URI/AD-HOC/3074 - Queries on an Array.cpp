// Author: Gustavo Policarpo
// Name: Queries on an Array
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3074

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#define _CRT_SECURE_NO_WARNINGS

#define gc getchar

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define REP(i,a,b) for( int i = (int) a; i <= (int) b; i++ )
#define PER(i,a,b) for( int i = (int) a; i >= (int) b; i-- )
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugPP(a) debug2(a.x, a.y)
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
 
using namespace std;
 
typedef long long int ll;
typedef pair <int, int> ii;

void scanint(int &x){
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

int tree[400040][32];
int lazy[400040][32];
int a[100010];

inline void propagate(int no, int i, int j, int op){
	if(!lazy[no][op]) return;
	tree[no][op] = (j-i+1)-tree[no][op];
	if(i!=j){
		lazy[no*2][op]^=1;
		lazy[no*2+1][op]^=1;
	}
	lazy[no][op] = 0;
}
void build(int no, int i, int j, int op){
	if(i==j){
		tree[no][op] = (bool)(a[i]&(1LL<<op));
		return;
	}
	register int L=no*2, R=L+1, mid=(i+j)/2;
	build(L, i, mid, op);
	build(R, mid+1, j, op);
	tree[no][op] = tree[L][op] + tree[R][op];
}

void update(int no, int i, int j, int a, int b, int op){
	propagate(no, i, j, op);
	if(i>j || i>b || j<a) return;
	if(i>=a && j<=b){
		lazy[no][op]^=1;
		propagate(no, i, j, op);
		return;
	}
	register int L=no*2, R=L+1, mid=(i+j)/2;
	update(L, i, mid, a, b, op);
	update(R, mid+1, j, a, b, op);
	tree[no][op] = tree[L][op] + tree[R][op];
}

int query(int no, int i, int j, int a, int b, int op){
	propagate(no, i, j, op);
	if(i>b || j<a || tree[no][op]==0) return 0;
	if(i>=a && j<=b) return tree[no][op];
	register int L=no*2, R=L+1, mid=(i+j)/2;
	int SL = query(L, i, mid, a, b, op);
	int SR = query(R, mid+1, j, a, b, op);
	return SL+SR;
}


int main(){
	
	int N; scanint(N);
		
	rep(i, 0, N) scanint(a[i]);
	
	rep(i, 0, 32){
		build(1, 0, N-1, i);
	}
	
	int Q; scanint(Q);
	char s[8]; int a, b, c;
	while(Q--){
		scanf("%s", s);
		if(s[0]=='S'){
			scanint(a); scanint(b);
			ll sum = 0;
			rep(i, 0, 32){
				ll qr = query(1, 0, N-1, a, b, i);
				sum += qr*(1LL<<i);
			}
			printf("%lld\n", sum);
		}else{
			scanint(a); scanint(b); scanint(c);
			update(1, 0, N-1, a, b, c);
		}
	}
	
	return 0;
}
