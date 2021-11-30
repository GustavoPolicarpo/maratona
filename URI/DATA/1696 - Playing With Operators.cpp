// Author: Gustavo Policarpo
// Name: Playing With Operators
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1696

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;


int N, Q, v[100010], tree[400040];

int build(int no, int i, int j){
	if(i==j){
		tree[no] = v[i];
		return 1;
	}
	int L = no*2, R = L+1, mid = (i+j)/2;
	int sl = build(L, i, mid);
	int sr = build(R, mid+1, j);
	int op = (sl&sr);
	//cout << no << " " << i << " " << j << " " << sl << " " << sr << " " << tree[L] << " " << tree[R] << '\n';
	if(op) tree[no] = tree[L] + tree[R];
	else tree[no] = tree[L] - tree[R];
	return op^1;
}

int update(int no, int i, int j, int x, int y){
	if(i>x || j<x) return 1;
	if(i==j){
		tree[no] = y;
		return 1;
	}
	int L = no*2, R = L+1, mid = (i+j)/2;
	int sl = update(L, i, mid, x, y);
	int sr = update(R, mid+1, j, x, y);
	int op = (sl&sr);
	if(op) tree[no] = tree[L] + tree[R];
	else tree[no] = tree[L] - tree[R];
	return op^1;
}

set <int> st;

int main(){
	
	int po2 = 1;
	while(po2<100000) st.insert(po2), po2*=2;
		
	string nm[] = {"Rusa", "Sanches"};
	
	int T; scanf("%d", &T);
	int x, y, op = 1;
	while(T--){
		scanf("%d %d", &N, &Q); 
		rep(i, 0, N) scanf("%d", &v[i]);
		while(!st.count(N)) v[N] = 0, N++;
		
		build(1, 0, N-1);
		
		rep(z, 0, Q+1){
			int val = tree[1];
			cout << val << " " << (val%2!=0 ? nm[op^1] : nm[op]) << '\n';
			
			if(z<Q){
				scanf("%d %d", &x, &y); x--;
				update(1, 0, N-1, x, y);
			}
		}
		
		op^=1;
		
	}
	
	return 0;
} 
