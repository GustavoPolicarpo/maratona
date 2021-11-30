// Author: Gustavo Policarpo
// Name: Distância Entre Amigos
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3050

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair <int, int> ii;

const int MAXV = 100010;

int tree[4*MAXV], lazy[4*MAXV];
int arr[MAXV];

inline void propagate(int no, int i, int j){
	/*DO NOT TO FORGET TO UPDATE THIS!!!*/
	if(!lazy[no]) return;
	tree[no] += lazy[no];
	if(i!=j){
		lazy[no*2] += lazy[no]; 
		lazy[no*2+1] += lazy[no];
	}
	lazy[no] = 0;
}

inline int merge(int L, int R){
	/*DO NOT TO FORGET TO UPDATE THIS!!!*/
	return max(L, R);
}
void build(int no, int i, int j){
	if(i==j){
		/*DO NOT TO FORGET TO UPDATE THIS!!!*/
		tree[no] = arr[i]+i;
		return;
	}
	int L=no*2, R=L+1, mid=(i+j)/2;
	build(L, i, mid);
	build(R, mid+1, j);
	tree[no] = merge(tree[L], tree[R]);
}

void update(int no, int i, int j, int a, int b, int v){
	propagate(no, i, j);
	if(i>j || i>b || j<a) return;
	if(i>=a && j<=b){
		/*DO NOT TO FORGET TO UPDATE THIS!!!*/
		lazy[no] += v;
		propagate(no, i, j);
		return;
	}
	int L=no*2, R=L+1, mid=(i+j)/2;
	update(L, i, mid, a, b, v);
	update(R, mid+1, j, a, b, v);
	tree[no] = merge(tree[L], tree[R]);
}

int query(int no, int i, int j, int a, int b){
	propagate(no, i, j);
	/*DO NOT TO FORGET TO UPDATE THIS!!!*/
	if(i>j || i>b || j<a) return 0;
	if(i>=a && j<=b) return tree[no];
	int L=no*2, R=L+1, mid=(i+j)/2;
	int SL = query(L, i, mid, a, b);
	int SR = query(R, mid+1, j, a, b);
	return merge(SL, SR);
}

int main(){

    int n; scanf("%d", &n); int i;
    for(i=1; i<=n; i++) scanf("%d", &arr[i]);
    
    build(1, 1, n);
    
    int ans = 0;
    for(i=1; i<=n; i++){
        int q1 = query(1, 1, n, 1, i-1);
        int q2 = query(1, 1, n, i+1, n);
        ans = max(ans, max(q1, q2)+arr[i]-1);
        update(1, 1, n, 1, i, 1);
        update(1, 1, n, i+1, n, -1);
    }
    
    printf("%d\n", ans);
    
	
	
	return 0;
}
