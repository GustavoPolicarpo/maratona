// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Produto do Intervalo
// Nível: 5
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1301

#define gc getchar_unlocked
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

int N, K, tree[400004], n[400004];

void build_tree(int node, int i, int j){
	if(i==j){
		tree[node]=n[i];
		return;
	}
	int L=node*2, R=node*2+1, mid=(i+j)/2;
	build_tree(L, i, mid);
	build_tree(R, mid+1, j);
	
	tree[node]=tree[L]*tree[R];
}

void update_tree(int node, int i, int j, int k, int val){
	if(i>j || k<i || k>j) return;
	if(i==j && i==k){
		tree[node]=val;
		return;
	}
	int L=node*2, R=node*2+1, mid=(i+j)/2;
	update_tree(L, i, mid, k, val);
	update_tree(R, mid+1, j, k, val);
	
	tree[node]=tree[L]*tree[R];
}

int query_tree(int node, int i, int j, int a, int b){
	if(i>j || b<i || a>j) return 1;
	if(i>=a && j<=b) return tree[node];
	int L=node*2, R=node*2+1, mid=(i+j)/2;
	int SL=query_tree(L, i, mid, a, b);
	int SR=query_tree(R, mid+1, j, a, b);
	
	return SL*SR;	
}

int main()
{
	while(scanf("%d %d", &N, &K)!=EOF){
		rep(i, 1, N+1){
			//scanf("%d", &n[i]);
			scanint(n[i]);
			if(n[i]>0) n[i]=1;
			else if(n[i]<0) n[i]=-1;
		}
		rep(i, 1, N*4+1) tree[i]=0;
		build_tree(1, 1, N);
		char op; int a, b;
		while(K--){
			scanf(" %c", &op);
			scanint(a), scanint(b);
			if(op=='P'){
				int out=query_tree(1, 1, N, a, b);
				if(out>0) printf("+");
				else if(out<0) printf("-");
				else printf("0");
			}
			else{
				if(b>0) b=1;
				else if(b<0) b=-1;
				update_tree(1, 1, N, a, b);
			}
		}
		printf("\n");
	}
	

return 0;
}



