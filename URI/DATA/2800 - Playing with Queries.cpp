// Author: Gustavo Policarpo
// Name: Playing with Queries
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2800

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

struct use{
	unordered_map<int, int> mapa;
	int pai;
};

int N, Q;
use tree[400040];
unordered_map <int, int> :: iterator it;
int v[100010], pos[100010];

void build(int no, int i, int j){
	if(i==j){
		tree[no].mapa[v[i]] = 1;
		pos[i] = no;
		return;
	}
	int L = no*2, R = L+1, mid = (i+j)/2;
	tree[L].pai = no, tree[R].pai = no;
	
	build(L, i, mid);
	build(R, mid+1, j);
	tree[no].mapa = tree[R].mapa;
	
	for(it = tree[L].mapa.begin(); it!=tree[L].mapa.end(); it++){
		tree[no].mapa[it->first] += it->second;
	}
}

void update(int i, int nv){
	int no = pos[i];
	while(42){
		tree[no].mapa[v[i]]--;
		tree[no].mapa[nv]++;
		if(no==1) break;
		no = tree[no].pai;
	}
	v[i] = nv;
}

int query(int no, int i, int j, int a, int b, int nv){
	if(i>j || i>b || j<a || !tree[no].mapa[nv]) return 0;
	if(i>=a && j<=b) return tree[no].mapa[nv];
	int L = no*2, R = L+1, mid = (i+j)/2;
	return query(L, i, mid, a, b, nv) + query(R, mid+1, j, a, b, nv);
}

int main(){
	scanf("%d %d", &N, &Q);
	rep(i, 0, N) scanf("%d", &v[i]);
	build(1, 0, N-1);
	int op, a, b, c;
	while(Q--){
		scanf("%d", &op);
		//op = rand()%2 +1;
		if(op==1){
			scanf("%d %d", &a, &c); a--;
			//a = rand()%N, c = rand()%100000+1;
			update(a, c);
		}else{
			scanf("%d %d %d", &a, &b, &c); a--, b--;
			//a = rand()%N, b = rand()%N, c = rand()%100000+1;
			if(a>b) swap(a, b);
			int tt = query(1, 0, N-1, a, b, c);
			printf("%d\n", b-a+1-tt);
		}
	}
	
	
}
