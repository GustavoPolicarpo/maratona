// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Surf Aquático
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2560

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;

void scanint(int &x){
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;
typedef pair <ll, ll> ii;

ii tree[800080];
ll v[200020], sum[200020];
int N, B;

void build(int no, int i, int j){
	if(i==j){
		tree[no]=ii(v[i], v[i]);
		return;
	}
	int L=no*2, R=L+1, mid=(i+j)/2;
	build(L, i, mid);
	build(R, mid+1, j);
	tree[no]=ii(max(tree[L].F, tree[R].F), min(tree[L].S, tree[R].S));
}

ii query(int no, int i, int j, int a, int b){
	if(i>j || i>b || j<a) return ii(0, INF);
	if(i>=a && j<=b) return tree[no];
	int L=no*2, R=L+1, mid=(i+j)/2;
	ii SL=query(L, i , mid, a, b);
	ii SR=query(R, mid+1, j, a, b);
	return ii(max(SL.F, SR.F), min(SL.S, SR.S));
}
int main(){

	while(scanf("%d %d", &N, &B)!=EOF){
		
		rep(i, 1, N+1){
			scanf("%lld", &v[i]);
			sum[i]=sum[i-1]+v[i];
		}
		
		build(1, 0, N+2);
		
		ll ans=0;
		rep(i, 1, N-B+2){
			ii aux=query(1, 0, N+2, i, i+B-1);
			//cout << aux.F << " " << aux.S << '\n';
			ans+=sum[i+B-1]-sum[i-1]-aux.F-aux.S;
		}
		
		printf("%lld\n", ans);
		
	}

	return 0;

}
