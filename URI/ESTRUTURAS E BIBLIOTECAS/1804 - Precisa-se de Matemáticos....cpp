// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Precisa-se de Matemáticos...
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1804

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int N, a[100010], Q;
int tree[4*100010];

void build(int no, int i, int j){
	if(i>j) return;
	if(i==j){
		tree[no] = a[i];
		return;
	}
	int L = no*2, R = no*2+1, mid = (i+j)/2;
	build(L, i, mid);
	build(R, mid+1, j);
	tree[no] = tree[L] + tree[R];
}

int query(int no, int i, int j, int a, int b){
	if(i>j || i>b || j<a) return 0;
	if(i>=a && j<=b) return tree[no];
	int L = no*2, R = no*2+1, mid = (i+j)/2;
	return query(L, i, mid, a, b) +
			query(R, mid+1, j, a, b);
}

void update(int no, int i, int j, int x, int v){
	if(i>j || i>x || j<x) return;
	if(i==j && i==x){
		tree[no] = v;
		return;
	}
	int L = no*2, R = no*2+1, mid = (i+j)/2;
	update(L, i, mid, x, v);
	update(R, mid+1, j, x, v);
	tree[no] = tree[L] + tree[R];
}

int main(){
	
	int N; cin >> N;

	rep(i, 0, N) scanf("%d", &a[i]);
	build(1, 0, N-1);
	char op; int a;
	
	while(scanf(" %c %d", &op, &a) !=EOF){
		if(op=='a'){
			update(1, 0, N-1, a-1, 0);
		}
		else{
			int out=query(1, 0, N-1, 0, a-2);
			printf("%d\n", out);
		}
	}
	
	return 0;
} 
