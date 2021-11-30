// Author: Gustavo Policarpo
// Name: Rangel and the Array Game I
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2848

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

#define N 100010
 
vector<int> tree[4*N], v;
int a[N];
 
void build(int no, int i, int j){
	if(i == j){
		tree[no].pb(a[i]);
		return;
	}
	int L = no*2, R = L+1, mid = (i+j)/2;
	build(L, i, mid);
	build(R, mid+1, j);
	merge(tree[L].begin(), tree[L].end(), tree[R].begin(), tree[R].end(), back_inserter(tree[no]));	
}
 
 
int query(int no, int i, int j, int a, int b, int v){
	if(i > b || j < a) return 0;
	if(i >= a && j <= b) return upper_bound(tree[no].begin(), tree[no].end(), v) - tree[no].begin();
	int L = no*2, R = L+1, mid = (i+j)/2;
	int aa = query(L, i, mid, a, b, v);
	int bb = query(R, mid+1, j, a, b, v);
	return aa + bb;
}

map<int, vector <int> > mapa;
int count(int l, int r, int k){
	vector <int> &vec = mapa[k];
	int ret = upper_bound(vec.begin(), vec.end(), r) - vec.begin();
	ret -= lower_bound(vec.begin(), vec.end(), l) - vec.begin();
	return ret;
}

int main(){
	
	int n, q;
	scanf("%d %d", &n, &q);
	rep(i, 0, n){
		scanf("%d", &a[i]);
		mapa[a[i]].pb(i);
		v.pb(a[i]);
	}
	
	sort(v.begin(), v.end());
	rep(i, 0, n) a[i] = upper_bound(v.begin(), v.end(), a[i]) - v.begin();
	build(1, 0, n-1);
	
	int l, r, k, g, d, ini, mid, fim, kht, ans, aux;
	while(q--){
		scanf("%d %d %d %d %d", &l, &r, &k, &g, &d); l--, r--;
		ini = 1, fim = n;
		while(ini<=fim){
			mid = (ini+fim)/2;
			aux = query(1, 0, n-1, l, r, mid);
			if(aux >= k){
				kht = mid;
				fim = mid-1;
			}else{
				ini = mid+1;
			}
		}
		kht = v[kht-1];
		ans = count(l, r, kht);
		printf("%d %d ", kht, ans);
		if(abs(g-ans) < abs(d-ans)) puts("G");
		else if(abs(g-ans) > abs(d-ans)) puts("D");
		else puts("E");
	}
	
	return 0;
} 
