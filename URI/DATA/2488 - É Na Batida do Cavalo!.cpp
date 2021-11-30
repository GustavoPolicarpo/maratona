// Author: Gustavo Policarpo
// Name: É Na Batida do Cavalo!
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2488

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

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, ii > iii;

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

int N, P, cnt=1;
int tree[40040], v[10010];
map <ii, int> mapa;

void build_tree(int node, int i, int j){
	if(i==j){
		tree[node]=v[i];
		return;
	}
	int L=node*2, R=node*2+1, mid=(i+j)/2;
	build_tree(L, i, mid);
	build_tree(R, mid+1, j);
	
	tree[node]=max(tree[L], tree[R]);
}

int query_tree(int node, int i, int j, int a, int b){
	if(b<i || a>j) return 0;
	if(i>=a && j<=b) return tree[node];
	
	int L=node*2, R=node*2+1, mid=(i+j)/2;
	int SL=query_tree(L, i, mid, a, b);
	int SR=query_tree(R, mid+1, j, a, b);
	
	return max(SL, SR);
}

int main()
{
	scanf("%d %d", &N, &P);
	ii aux, last; 
	
	scanf("%d %d", &aux.F, &aux.S);
	mapa[aux]=cnt++;
	last=aux;
	rep(i, 1, N){
		scanf("%d %d", &aux.F, &aux.S);
		v[cnt]=(aux.F-last.F)*(aux.F-last.F) + (aux.S-last.S)*(aux.S-last.S);
		mapa[aux]=cnt++;
		last=aux;
	}
	
	build_tree(1, 1, N);
	
	while(P--){
		scanf("%d %d", &aux.F, &aux.S);
		scanf("%d %d", &last.F, &last.S);
		int a=mapa[aux], b=mapa[last];
		if(a>b) swap(a, b);
		a++;
		double ans=sqrt(query_tree(1, 1, N, a, b));
		printf("%.2lf\n", ans);
	}
	
	return 0;
	
}
