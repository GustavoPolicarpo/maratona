// Author: Gustavo Policarpo
// Name: Line-up
// Level: 10
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2572

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <double, int> ii;

const ll mod = 1e9+7;
const int INF = 0x3f3f3f3f;
#define EPS 1e-9

int N, K, R;
int v[200020];

vector <int> tree[800080];

void build(int no, int i, int j){
	
	if(i==j){
		if(v[i]) tree[no].pb(-v[i]);
		return;
	}
	
	int L=no*2, R=L+1, mid=(i+j)/2;
	build(L, i, mid);
	build(R, mid+1, j);
	
	merge(tree[L].begin(), tree[L].end(), tree[R].begin(), tree[R].end(), back_inserter(tree[no]));
	while(tree[no].size()>K) tree[no].pop_back();
}

vector <int> query(int no, int i, int j, int a, int b){
	
	vector <int> ret;
	if(i>j || i>b || j<a) return ret;
	
	if(i>=a && j<=b) return tree[no];
	
	int L=no*2, R=L+1, mid=(i+j)/2;
	
	vector <int> SL=query(L, i, mid, a, b);
	vector <int> SR=query(R, mid+1, j, a, b);
	
	while(SL.size()>K) SL.pop_back();
	while(SR.size()>K) SR.pop_back();
	merge(SL.begin(), SL.end(), SR.begin(), SR.end(), back_inserter(ret));
	while(ret.size()>K) ret.pop_back();
	return ret;
}


int main(){
	
	scanf("%d %d %d", &N, &K, &R);
		
	rep(i, 1, N+1) scanf("%d", &v[i]);
	
	build(1, 1, N);
	
	int a, b;
	while(R--){
		scanf("%d %d", &a, &b);
		
		vector <int> ans=query(1, 1, N, a, b);
		
		ll resp=0; if(ans.size()) resp=1;
		rep(i, 0, ans.size()){
			resp*=(ans[i]*-1);
			if(resp>mod) resp%=mod;
		}
		
		printf("%lld\n", resp);
		
	}
		
	return 0;
	
}
