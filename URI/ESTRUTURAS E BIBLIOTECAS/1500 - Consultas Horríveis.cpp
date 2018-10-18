// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Consultas Horríveis
// Nível: 7
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1500

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
#define error 0.0001

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

int N, C; 
ll tree[4000004], lazy[4000004];

void propagate(int no, int i, int j){
	if(lazy[no]!=0){
		tree[no]+=(j-i+1)*lazy[no];
		
		if(i!=j){
			lazy[no*2]+=lazy[no];
			lazy[no*2+1]+=lazy[no];
		}
		lazy[no]=0;
	}
	return;
}

ll query_tree(int no, int i, int j, int a, int b){
	
	if(i>j || i>b || j<a) return 0;
	propagate(no, i, j);
	
	if(i>=a && j<=b) return tree[no];
	
	int L=no*2, R=no*2+1, mid=(i+j)/2;
	ll SL=query_tree(L, i, mid, a, b);
	ll SR=query_tree(R, mid+1, j, a, b);
	
	return SL+SR;	
}
void update_tree(int no, int i, int j, int a, int b, ll val){
	
	propagate(no, i, j);
	if(i>j || i>b || j<a) return;
	
	if(i>=a && j<=b){
		tree[no]+=(j-i+1)*val;
		if(a!=b){
			lazy[no*2]+=val;
			lazy[no*2+1]+=val;
		}
		return;
	}
	
	int L=no*2, R=no*2+1, mid=(i+j)/2;
	update_tree(L, i, mid, a, b, val);
	update_tree(R, mid+1, j, a, b, val);
	
	tree[no]=tree[L]+tree[R]; 
}
int main(){
	int T; //cin >> T;
	scanint(T);
	while(T--){
		
		scanint(N), scanint(C);
		//scanf("%d %d", &N, &C);
		
		rep(i, 0, N*4+1) lazy[i]=0, tree[i]=0;
	
		int op, a, b;
		ll v;
		rep(i, 0, C){
			scanint(op), scanint(a), scanint(b);
			//scanf("%d %d %d", &op, &a, &b);
			if(op==1){
				ll out=query_tree(1, 1, N, a, b);
				printf("%lld\n", out);
			}
			else{
				scanf("%lld", &v);
				update_tree(1, 1, N, a, b, v);
			}
		}
	}
	
return 0;
}
