// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Compras em FdI
// Nível: 4
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2531

#include <bits/stdc++.h>
 
using namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define INF 0x3f3f3f3f
int tree[4*100010][2];
int a[100010];
 
void build(int no, int i, int j){
 
	if(i > j) return;
	if(i == j){
		tree[no][0] = tree[no][1] = a[i];
		return;
	}
	int L = no*2, R = no*2+1, mid = (i+j)/2;
	build(L, i, mid);
	build(R, mid+1, j);
	tree[no][0] = min(tree[L][0], tree[R][0]);
	tree[no][1] = max(tree[L][1], tree[R][1]);
}
 
int querymenor(int no, int i, int j, int a, int b){
 
	if(i > b || j < a) return INF;
	if(i >= a && j <= b) return tree[no][0];
	int L = no*2, R = no*2+1, mid = (i+j)/2;
	return min(querymenor(L, i, mid, a, b), querymenor(R, mid+1, j, a, b));
}
 
int querymaior(int no, int i, int j, int a, int b){
 
	if(i > b || j < a) return -INF;
	if(i >= a && j <= b) return tree[no][1];
	int L = no*2, R = no*2+1, mid = (i+j)/2;
	return max(querymaior(L, i, mid, a, b), querymaior(R, mid+1, j, a, b));
}
 
void updat(int no, int i, int j, int x, int v){
	if(x > j || x < i) return;
	if(i == j && i == x){
		tree[no][0] = tree[no][1] = v;
		return;
	}
	int L = no*2, R = no*2+1, mid = (i+j)/2;
	updat(L, i, mid, x, v);
	updat(R, mid+1, j, x, v);
	tree[no][0] = min(tree[L][0], tree[R][0]);
	tree[no][1] = max(tree[L][1], tree[R][1]);
}
 
int main(){
 
	int n;
	while(scanf("%d", &n) != EOF){
 
		rep(i, 0, n)
			scanf("%d", &a[i]);
		build(1, 0, n-1);
 
		int op;
		scanf("%d", &op);
		rep(i, 0, op){
			int x;
			scanf("%d", &x);
			if(x == 1){
				int ind, v;
				scanf("%d%d", &ind, &v);
				ind--;
				updat(1, 0, n-1, ind, v);
			}else{
				int a, b;
				scanf("%d%d", &a, &b);
				a--;b--;
				printf("%d\n", querymaior(1, 0, n-1, a, b) - querymenor(1, 0, n-1, a, b));
			}
		}	
	}
 
 
 
	return 0;
}
