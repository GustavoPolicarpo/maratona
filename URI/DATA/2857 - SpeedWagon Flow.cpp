// Author: Gustavo Policarpo
// Name: SpeedWagon Flow
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2857

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;

int tree[4*100010];
int n, m;

int query(int no, int i, int j, int a, int b){
	if(i>j || i>b || j<a) return 0;
	if(i>=a && j<=b) return tree[no];
	int L = no*2, R = no*2+1, mid = (i+j)/2;
	return query(L, i, mid, a, b) +
			query(R, mid+1, j, a, b);
}

void update(int no, int i, int j, int a, int b, int v){
	if(i>j || i>b || j<a) return;
	if(i>=a && j<=b){
		tree[no]+=v;
		return;
	}
	int L = no*2, R = no*2+1, mid = (i+j)/2;
	update(L, i, mid, a, b, v);
	update(R, mid+1, j, a, b, v);
	tree[no] = tree[L] + tree[R];
}

int main(){
    
    int op, a, b, c, d;
	scanf("%d %d", &n, &m);
	while(m--){
		scanf("%d", &op);
		if(op==1){
			scanf("%d %d", &a, &b); a--;
			update(1, 0, n-1, a, a, b);
		}else{
			scanf("%d %d %d %d", &a, &b, &c, &d); a--, b--, c--, d--;
			int tt = query(1, 0, n-1, a, b) + query(1, 0, n-1, c, d);
			if(c>=a && d<=b) tt-=query(1, 0, n-1, c, d);
			else if(a>=c && b<=d) tt-=query(1, 0, n-1, a, b);
			else if(c>=a && c<=b) tt-=query(1, 0, n-1, c, b);
			else if(a>=c && a<=d) tt-=query(1, 0, n-1, a, d);
			printf("%d\n",  tt);
		}
	}
	
	
	
    return 0;
}  
