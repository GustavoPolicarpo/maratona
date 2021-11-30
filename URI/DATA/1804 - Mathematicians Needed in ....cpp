// Author: Gustavo Policarpo
// Name: Mathematicians Needed in ...
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1804

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
#define error 1e-12

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int N, K, v[100001], tree[400004];

void build_tree(int no, int i, int j)
{
	if(i>j) return;
	if(i==j){
		tree[no]=v[i];
		return;
	}
	int L=2*no, R=2*no+1, mid=(i+j)/2;
	build_tree(L, i, mid);
	build_tree(R, mid+1, j);
	tree[no]=(tree[L] + tree[R]);
}

int query_tree(int no, int i, int j, int a, int b)
{
	if(b<i || a>j) return 0;
	if(i>=a && j<=b) return tree[no];
	int L=2*no, R=2*no+1, mid=(i+j)/2;
	int SL=query_tree(L, i, mid, a, b);
	int SR=query_tree(R, mid+1, j, a, b);
	
	return (SL + SR);
}

void update_tree(int no, int i, int j, int k, int val)
{
	if(k<i || k>j) return;
	if(i==k && j==k){
		tree[no]=val;
		return;
	}
	int L=2*no, R=2*no+1, mid=(i+j)/2;
	update_tree(L, i, mid, k, val);
	update_tree(R, mid+1, j, k, val);
	tree[no]= tree[L]+tree[R];
}

int main()
{
	int N; cin >> N;
	rep(i, 1, N+1) scanf("%d", &v[i]);
	build_tree(1, 1, N);
	char op; int a;
	while(scanf(" %c %d", &op, &a) !=EOF){
		if(op=='a'){
			update_tree(1, 1, N, a, 0);
		}
		else{
			int out=query_tree(1, 1, N, 1, a-1);
			printf("%d\n", out);
		}
	}
}

