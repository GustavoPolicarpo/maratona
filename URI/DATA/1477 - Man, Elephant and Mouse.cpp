// Author: Gustavo Policarpo
// Name: Man, Elephant and Mouse
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1477

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

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

struct Mao{
    int a, b, c;
    
    Mao(){}
    Mao(int a) : a(a), b(0), c(0) {}
    Mao(int a, int b, int c) : a(a), b(b), c(c) {}
    
    Mao rotate(int n){
        if(n==1) swap(a, b), swap(c, a);
        else if(n==2) swap(b, c), swap(c, a);
        return Mao(a, b, c);
    }
    
    Mao operator +(Mao x){
        return Mao(a+x.a, b+x.b, c+x.c);
    }
    
};

int N, M, lazy[400004];
Mao tree[400004];

void build_tree(int node, int i, int j){
    lazy[node]=0;
    if(i==j){
        tree[node]=Mao(1);
        return;
    }
    int L=node*2, R=node*2+1, mid=(i+j)/2;
    build_tree(L, i, mid);
    build_tree(R, mid+1, j);

    tree[node]=tree[L]+tree[R];
}

void propagate(int node, int i, int j){
	
    if(lazy[node]!=0){
        int n=(lazy[node])%3;
        tree[node].rotate(n);
        if(i!=j){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    return; 
}
void update_tree(int node, int i, int j, int a, int b){
    propagate(node, i, j);
    if(i>j || a>j || b<i) return;
    
    if(i>=a && j<=b){
        lazy[node]++;
        propagate(node, i, j);
        return;
    }
    int L=node*2, R=node*2+1, mid=(i+j)/2;
    update_tree(L, i, mid, a, b);
    update_tree(R, mid+1, j, a, b);
    
    tree[node]=tree[L]+tree[R];
}

Mao query_tree(int node, int i, int j, int a, int b){
	if(i>j || a>j || b<i) return Mao(0);
    propagate(node, i, j);
    if(i>=a && j<=b) return tree[node];
    
    int L=node*2, R=node*2+1, mid=(i+j)/2;
    return query_tree(L, i, mid, a, b) +
            query_tree(R, mid+1, j, a, b);
}

int main()
{

    while(scanf("%d %d", &N, &M)!=EOF){
        build_tree(1, 1, N);
        char op; int a, b;
        while(M--){
            scanf(" %c", &op);
            scanint(a), scanint(b);
            if(op=='M'){
                update_tree(1, 1, N, a, b);
            }
            else{
                Mao out=query_tree(1, 1, N, a, b);
                printf("%d %d %d\n", out.a, out.b, out.c);
            }
        }
        printf("\n");
    }
    
return 0;
}

