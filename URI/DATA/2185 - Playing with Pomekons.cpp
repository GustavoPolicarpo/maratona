// Author: Gustavo Policarpo
// Name: Playing with Pomekons
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2185

//#define gc getchar_unlocked
#include<bits/stdc++.h>

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

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, M, tree[400004], lazy[400004], n[400004];

void build_tree(int node, int i, int j){
	lazy[node]=-1;
	if(i==j){
		tree[node]=n[i];
		return;
	}
	int L=node*2, R=node*2+1, mid=(i+j)/2;
	build_tree(L, i, mid), build_tree(R, mid+1, j); 
			tree[node]=tree[L]^tree[R];
}

void propagate(int node, int i, int j){
	if(lazy[node]!=-1){
		tree[node]=((j-i+1)%2)*lazy[node];
		if(i!=j){
			lazy[node*2]=lazy[node];
			lazy[node*2+1]=lazy[node];
		}
		lazy[node]=-1;
	}
}
void update_tree(int node, int i, int j, int a, int b, int val){
	propagate(node, i, j);
	if(i>j || a>j || b<i) return;
	
	
	if(i>=a && j<=b){
		lazy[node]=val;
		propagate(node, i, j);
		return;
	}
	int L=node*2, R=node*2+1, mid=(i+j)/2;
	update_tree(L, i, mid, a, b, val);
	update_tree(R, mid+1, j, a, b, val);
	
	tree[node]=tree[L]^tree[R];
}

int query_tree(int node, int i, int j, int a, int b){
	propagate(node, i, j);
	return tree[node];
}
int main()
{
	scanf("%d %d", &N, &M);
	rep(i, 1, N+1) scanf("%d", &n[i]);
	build_tree(1, 1, N);
	int a, b, v;
	while(M--){
		scanf("%d %d %d", &a, &b, &v);
		update_tree(1, 1, N, a, b, v);
		int r=tree[1];//query_tree(1, 1, N, 1, N);
		//cout << r << endl;
		if(r) puts("Possivel");
		else puts("Impossivel");
	}

return 0;

}
