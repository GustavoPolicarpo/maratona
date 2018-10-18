// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Árvore Binária de Busca
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1195

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

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

struct node{
	int val, left, right;
	node() {}
	node(int v) : val(v), left(0), right(0) {};
};
vector <node> tree;

void insert(int no, int val){
	if(val > tree[no].val){
		if(tree[no].right) insert(tree[no].right, val);
		else{
			tree[no].right=tree.size();
			tree.pb(node(val));
		}
	}else{
		if(tree[no].left) insert(tree[no].left, val);
		else{
			tree[no].left=tree.size();
			tree.pb(node(val));
		}
	}
	return;
}

void prefixa(int no){
	printf(" %d", tree[no].val);
	if(tree[no].left) prefixa(tree[no].left);
	if(tree[no].right) prefixa(tree[no].right);
}
void insfixa(int no){
	if(tree[no].left) insfixa(tree[no].left);
	printf(" %d", tree[no].val);
	if(tree[no].right) insfixa(tree[no].right);
}
void posfixa(int no){
	if(tree[no].left) posfixa(tree[no].left);
	if(tree[no].right) posfixa(tree[no].right);
	printf(" %d", tree[no].val);
}

int main()
{
	int T, N, u; scanint(T);
	rep(z, 1, T+1){
		scanint(N);
		tree.clear();
		
		scanint(u);
		tree.pb(node(u));
		
		rep(i, 1, N){
			scanint(u);
			insert(0, u);
		}
		
		printf("Case %d:\n", z);
		printf("Pre.:"); prefixa(0); printf("\n");
		printf("In..:"); insfixa(0); printf("\n");
		printf("Post:"); posfixa(0); printf("\n");
		printf("\n");
		
	}

	return 0;
	
}
