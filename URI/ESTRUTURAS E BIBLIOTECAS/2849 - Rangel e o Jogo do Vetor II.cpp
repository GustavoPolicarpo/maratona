// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Rangel e o Jogo do Vetor II
// Nível: 7
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2849

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

 
int a[100010], conver[100010], cnt = 1;
ii v[100010];

struct Node{
	int l, r, q;
};
Node node[20*100010];
int root[100010];

void update(int &no, int pr, int i, int j, int k){
	no = cnt++;
	node[no] = node[pr];
	if(i==j && i==k){
		node[no].q++;
		node[no].l = node[no].r = 0;
		return;
	}
	int mid = (i+j)/2;
	if(k<=mid) update(node[no].l, node[pr].l, i, mid, k);
	else update(node[no].r, node[pr].r, mid+1, j, k);
	node[no].q = node[node[no].l].q + node[node[no].r].q;
}


int query(int no, int pr, int i, int j, int k){
	if(i==j) return i;
	int t = node[node[no].l].q - node[node[pr].l].q;
	int mid = (i+j)/2;
	if(t>=k) return query(node[no].l, node[pr].l, i, mid, k);
	else return query(node[no].r, node[pr].r, mid+1, j, k-t);
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
	
	rep(i, 1, n+1){
		scanf("%d", &v[i].F), v[i].S = i;
		mapa[v[i].F].pb(i);
	}
	
	sort(v+1, v+n+1);
	
	rep(i, 1, n+1){
		a[v[i].S] = cnt;
		conver[cnt++] = v[i].F;
	}
	
	//rep(i, 1, n+1) cout << a[i] << " "; cout << "\n";
	
	cnt = 1;
	rep(i, 1, n+1) update(root[i], root[i-1], 1, n, a[i]);
	
	int l, r, k, g, d, pos, kht, ans;
	while(q--){
		scanf("%d %d %d %d %d", &l, &r, &k, &g, &d);
		pos = query(root[r], root[l-1], 1, n, k);
		kht = conver[pos];
		ans = count(l, r, kht);
		printf("%d %d ", kht, ans);
		if(abs(g-ans) < abs(d-ans)) puts("G");
		else if(abs(g-ans) > abs(d-ans)) puts("D");
		else puts("E");
	}
	
	return 0;
} 
