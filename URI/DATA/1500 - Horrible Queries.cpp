// Author: Gustavo Policarpo
// Name: Horrible Queries
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1500

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

int N, K;
ll tree[4000004], lazy[4000004];



ll query_tree(int node, int a, int b, int i, int j) {
	
	if(a > b || a > j || b < i) return 0; 

	if(lazy[node] != 0) { 
   		tree[node] += (b-a+1)*lazy[node]; 

		if(a != b) {
			lazy[node*2] += lazy[node];
    			lazy[node*2+1] += lazy[node]; 
		}

   		lazy[node] = 0; 
  	}

	if(a >= i && b <= j) 
		return tree[node];

	ll q1 = query_tree(node*2, a, (a+b)/2, i, j); 
	ll q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); 

	ll res = (q1 + q2); 
	
	return res;
}

void update_tree(int node, int a, int b, int i, int j, ll value) {
  
  	if(lazy[node] != 0) { 
   		tree[node] += (b-a+1)*lazy[node]; 

		if(a != b) {
			lazy[node*2] += lazy[node];
    			lazy[node*2+1] += lazy[node]; 
		}

   		lazy[node] = 0; 
  	}
  
	if(a > b || a > j || b < i) 
		return;
    
  	if(a >= i && b <= j) { 
    		tree[node] += (b-a+1)*value;

		if(a != b) { 
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); 
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); 

	tree[node] = (tree[node*2] + tree[node*2+1]);
}

int main()
{
	int T; cin >> T;
	while(T--){
		scanf("%d %d", &N, &K);
		
		memset(lazy, 0, sizeof lazy);
		memset(tree, 0, sizeof tree);
		
		ll op, a, b, v;
		rep(i, 0, K){
			scanf("%lldd", &op);
			if(op==1){
				scanf("%lld %lld", &a, &b);
				ll out=query_tree(1, 1, N, a, b);
				printf("%lld\n", out);
			}
			else{
				scanf("%lld %lld %lld", &a, &b, &v);
				update_tree(1, 1, N, a, b, v);
			}

		}
	}
	
return 0;	
}
