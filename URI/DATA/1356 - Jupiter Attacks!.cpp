// Author: Gustavo Policarpo
// Name: Jupiter Attacks!
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1356

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F3F3F3F
#define MAXV 100001

#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
typedef pair < ll, ii > iii;

int B, P, L, N; 
ll tree[400040], expo[100010], mod;

void update_tree(int node, int i, int j, int k, int v){
    if(i==j){
        tree[node]=v;
        return;
    }
    int L=node*2, R=node*2+1, mid=(i+j)/2;
    
    if(k<=mid) update_tree(L, i, mid, k, v);
    else update_tree(R, mid+1, j, k, v);
//  cout << tree[L] << " " << tree[R] << " " << i << " " << j << " " << l  << " " << node << endl;
    tree[node]=(tree[R]+(tree[L]*expo[j-mid])%mod)%mod;
}

ll query_tree(int node, int i, int j, int a, int b){
    if(i==a && j==b) return tree[node];
    
    int L=node*2, R=node*2+1, mid=(i+j)/2;
    
    if(b<=mid) return query_tree(L, i, mid, a, b);
    else if(a>mid) return query_tree(R, mid+1, j, a, b);
    
    ll SL=query_tree(L, i, mid, a, mid);
    ll SR=query_tree(R, mid+1, j, mid+1, b);
    return (SR+(SL*expo[b-mid])%mod)%mod;
}

int main()
{
    expo[0]=1;
    while(scanf("%d %d %d %d", &B, &P, &L, &N) and B){
        memset(tree, 0, sizeof tree); mod=P;
        rep(i, 1, L+1) expo[i]=(expo[i-1]*ll(B))%mod;
        
        char op; int a, b;
        while(N--){
            scanf(" %c %d %d", &op, &a, &b);
            
            if(op=='E') update_tree(1, 1, L, a, b);
            else printf("%lld\n", query_tree(1, 1, L, a, b)%mod);
        } 
        printf("-\n");
        
    }
    
return 0;

}
