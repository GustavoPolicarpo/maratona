// Author: Gustavo Policarpo
// Name: Interval Product
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1301

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

int N, K, v[100001], tree[400001];

void build_tree(int no, int i, int j)
{
	if(i>j) return;
	if(i==j){
		if(v[i]>0) tree[no]=1;
		else if(v[i]<0) tree[no]=-1;
		else tree[no]=0;
		return;
	}
	int L=2*no, R=2*no+1, mid=(i+j)/2;
	build_tree(L, i, mid);
	build_tree(R, mid+1, j);
	tree[no]=tree[L]*tree[R];
}

int query_tree(int no, int i, int j, int a, int b)
{
	if(b<i || a>j) return 1;
	if(i>=a && j<=b) return tree[no];
	int L=2*no, R=2*no+1, mid=(i+j)/2;
	int SL=query_tree(L, i, mid, a, b);
	int SR=query_tree(R, mid+1, j, a, b);
	
	return SL*SR;
}

void update_tree(int no, int i, int j, int k, int val)
{
	if(k<i || k>j) return;
	if(i==k && j==k){
		if(val>0) tree[no]=1;
		else if(val<0) tree[no]=-1;
		else tree[no]=0;
		return;
	}
	int L=2*no, R=2*no+1, mid=(i+j)/2;
	update_tree(L, i, mid, k, val);
	update_tree(R, mid+1, j, k, val);
	tree[no]=tree[L]*tree[R];
}

int main()
{
	while(scanf("%d %d", &N, &K) !=EOF){
		rep(i, 1, N+1)
			scanf("%d", &v[i]);
		build_tree(1, 1,  N);
		char op; int a, b;
		while(K--){
			cin >> op >> a >> b;
			if(op=='C'){
				update_tree(1, 1, N, a, b);
			}
			else{
				int out=query_tree(1, 1, N, a, b);
				//cout << out << endl;
				if(out<0) printf("-");
				else if(out==0) printf("0");
				else printf("+");
			}
		}
		printf("\n");
	}
}

