// Author: Gustavo Policarpo
// Name: Friday The 13th
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2559

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

struct use{
	int val, sete, treze;
	vector <ii> lazy;
};

int N, Q, v[200020];
use tree[800080];

void join(use &M, use L, use R){
	M.val = L.val + R.val;
	M.sete = L.sete + R.sete;
	M.treze = L.treze + R.treze;
	vector <ii> aux;
	swap(M.lazy, aux);
	aux.clear();
}

void build(int no, int i, int j){
	if(i==j){
		tree[no].val = v[i];
		tree[no].sete = (v[i]==7);
		tree[no].treze = (v[i]==13);
		tree[no].lazy.clear();
		return;
	}
	int L = no*2, R = L+1, mid = (i+j)/2;
	build(L, i, mid);
	build(R, mid+1, j);
	join(tree[no], tree[L], tree[R]);
}

void propagate(int no, int a, int b){
	if(!tree[no].lazy.size()) return;
	vector <ii> go;
	int sete = 7;
	int treze = 13;
	
	rep(i, 0, tree[no].lazy.size()){
		ii aux = tree[no].lazy[i];
		if(aux.F==aux.S) continue;
		if(aux.F==7 && tree[no].sete==0) continue;
		if(aux.F==13 && tree[no].treze==0) continue;
		
		if(sete==aux.F && aux.S!=7 && aux.S!=13) go.pb(ii(7, aux.S));
		if(treze==aux.F && aux.S!=7 && aux.S!=13) go.pb(ii(13, aux.S));
		if(sete==aux.F) sete=aux.S;
		if(treze==aux.F) treze=aux.S;
		
		if(aux.F==7){ 
			int diff = aux.S-7, qt = tree[no].sete;
			tree[no].val += qt*diff;
			tree[no].sete = 0;
			tree[no].sete += qt*(aux.S==7);
			tree[no].treze += qt*(aux.S==13);
		}
		if(aux.F==13){
			int diff = aux.S-13, qt = tree[no].treze;
			tree[no].val += qt*diff;
			tree[no].treze = 0;
			tree[no].sete += qt*(aux.S==7);
			tree[no].treze += qt*(aux.S==13);
		}
		/*if(a!=b){
			tree[no*2].lazy.pb(tree[no].lazy[i]);
			tree[no*2+1].lazy.pb(tree[no].lazy[i]);
		}*/
	}
	
	if(a!=b){
		int vs = 0, vt = 0;
		rep(i, 0, go.size()){
			if(go[i].F==7) vs = 1;
			if(go[i].F==13) vt = 1;
			tree[no*2].lazy.pb(go[i]);
			tree[no*2+1].lazy.pb(go[i]);
		}
		if(sete!=7 && !vs){
			tree[no*2].lazy.pb(ii(7, sete));
			tree[no*2+1].lazy.pb(ii(7, sete));
		}
		if(sete!=13 && !vt){
			tree[no*2].lazy.pb(ii(13, treze));
			tree[no*2+1].lazy.pb(ii(13, treze));
		}
	}
	

	vector <ii> aux;
	swap(tree[no].lazy, aux);
	aux.clear();
}

void update1(int no, int i, int j, int a, int val){
	propagate(no, i, j);
	if(i>j || i>a || j<a) return;
	if(i==j && i==a){
		tree[no].val = val;
		tree[no].sete = (val==7);
		tree[no].treze = (val==13);
		return;
	}
	int L = no*2, R = L+1, mid = (i+j)/2;
	update1(L, i, mid, a, val);
	update1(R, mid+1, j, a, val);
	join(tree[no], tree[L], tree[R]);
}

void update2(int no, int i, int j, int a, int b, int val1, int val2){
	propagate(no, i, j);
	if(i>j || i>b || j<a) return;
	if(i>=a && j<=b){
		if(val1==7 && tree[no].sete>0) tree[no].lazy.pb(ii(val1, val2));
		if(val1==13 && tree[no].treze>0) tree[no].lazy.pb(ii(val1, val2));
		propagate(no, i, j);
		return;
	}
	int L = no*2, R = L+1, mid = (i+j)/2;
	update2(L, i, mid, a, b, val1, val2);
	update2(R, mid+1, j, a, b, val1, val2);
	join(tree[no], tree[L], tree[R]);
}

int query(int no, int i, int j, int a, int b){
	propagate(no, i, j);
	if(i>j || i>b || j<a) return 0;
	if(i>=a && j<=b) return tree[no].val;
	int L = no*2, R = L+1, mid = (i+j)/2;
	int SL = query(L, i, mid, a, b);
	int SR = query(R, mid+1, j, a, b);
	return SL+SR;
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d", &N)!=EOF){
		
		rep(i, 0, N) scanf("%d", &v[i]);
		build(1, 0, N-1);
		
		scanf("%d", &Q); int op, a, b, c, d;
		while(Q--){
			scanf("%d", &op);
			if(op==1){
				scanf("%d %d", &a, &b); a--;
				update1(1, 0, N-1, a, b);
			}
			if(op==2){
				scanf("%d %d %d %d", &a, &b, &c, &d); a--, b--;
				if(a>b) swap(a, b);
				update2(1, 0, N-1, a, b, c, d);
			}
			if(op==3){
				scanf("%d %d", &a, &b); a--, b--;
				if(a>b) swap(a, b);
				printf("%d\n", query(1, 0, N-1, a, b));
				
			}
		}
		
		//rep(i, 0, N) cout << query(1, 0, N-1, i, i) << " "; puts("");
		
	}
	
	return 0;
}
