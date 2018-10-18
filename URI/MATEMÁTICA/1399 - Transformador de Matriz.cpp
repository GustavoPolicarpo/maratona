// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Transformador de Matriz
// Nível: 5
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1399

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int n, m, u, v[300300], ans[300300];
int min_tree[1200120], max_tree[1200120];

void build_tree(int node, int i, int j){
	if(i==j){
		ans[i]=node;
		min_tree[node]=v[i];
		max_tree[node]=v[i];
		return;
	}
	int L=node*2, R=L+1, mid=(i+j)/2;
	
	build_tree(L, i, mid),
	build_tree(R, mid+1, j);
	
	min_tree[node]=min(min_tree[L], min_tree[R]);
	max_tree[node]=max(max_tree[L], max_tree[R]);
}

void update_tree(int node, int i, int j, int a, int val){
	if(i>a || j<a) return;
	
	if(i==j && j==a){
		min_tree[node]=val,	
		max_tree[node]=val;
		return;
	}
	
	int L=node*2, R=L+1, mid=(i+j)/2;
	
	update_tree(L, i, mid, a, val),
	update_tree(R, mid+1, j, a, val);
	
	min_tree[node]=min(min_tree[L], min_tree[R]);
	max_tree[node]=max(max_tree[L], max_tree[R]);
}

int query_tree(int node, int i, int j, int a, int b, int val){
	if(i>b || j<a) return 0;
	
	if(i>=a && j<=b){
		if(min_tree[node]>=val) return 0;
		else if(max_tree[node]<val) return j-i+1;
	}
	
	int L=node*2, R=L+1, mid=(i+j)/2;
	
	int QL=query_tree(L, i, mid, a, b, val);
	int QR=query_tree(R, mid+1, j, a, b, val);
	
	return QL+QR;
}

int main()
{
	scanint(n), scanint(m), scanint(u);
	rep(i, 1, n+1) scanint(v[i]);
	
	//build_tree(1, 1, n);
	
	int l, r, val, p;
	while(m--){
		scanint(l), scanint(r), scanint(val), scanint(p);
		//ll k=query_tree(1, 1, n, l, r, val);
		ll k=0;
		rep(i, l, r+1) if(v[i]<val) k++;
		
		v[p]=k*u/(r-l+1);
		//update_tree(1, 1, n, p, k*u/(r-l+1));
	}
	
	rep(i, 1, n+1)
	printf("%lld\n", v[i]);

	return 0;
	
}
