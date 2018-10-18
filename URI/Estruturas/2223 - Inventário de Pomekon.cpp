// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Inventário de Pomekon
// Nível: 5
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2223

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
#define MAXN 100001
#define mod 1000000007
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/


//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, n[100010];
ll tree[400040];

struct dois{
	int v, k;
};
struct um{
	int id, a, b, cnt;
};

void build_tree(int node, int i, int j){
	if(i>j) return;
	if(i==j){
		tree[node]=n[i];
		return;
	}
	int L=node*2, R=node*2+1, mid=(i+j)/2;
	build_tree(L, i, mid);
	build_tree(R, mid+1, j);
	tree[node]=tree[L]+tree[R];
}

void update_tree(int node, int i, int j, int k, int val){
	if(i>j || k<i || k>j) return;
	if(i==k && j==k){
		tree[node]=val;
		return;
	}
	int L=node*2, R=node*2+1, mid=(i+j)/2;
	update_tree(L, i, mid, k, val);
	update_tree(R, mid+1, j, k, val);
	tree[node]=tree[L]+tree[R];
}

ll query_tree(int node, int i, int j, int a, int b){
	if(i>j || i>b || j<a) return 0;
	if(i>=a && j<=b) return tree[node];
	int L=node*2, R=node*2+1, mid=(i+j)/2;
	ll SL=query_tree(L, i, mid, a, b);
	ll SR=query_tree(R, mid+1, j, a, b);
	return SL+SR;
}
vector <um> out[100010];
vector <dois> in;
ll ans[100010];
int main()
{
	int T; cin >> T;
	while(T--){
		
		scanf("%d", &N);	
		rep(i, 1, N+1) scanf("%d", &n[i]);

		build_tree(1, 1, N);
		
		int Q; cin >> Q;
		rep(i, 0, Q+1){
			out[i].clear();
			ans[i]=0;
		} in.clear();
		
		int op, cnt=0;
		um a; dois b;
		while(Q--){
			scanf("%d", &op);
			if(op==2){
				scanf("%d %d", &b.k, &b.v);
				in.pb(b);
			}
			else{
				scanf("%d %d %d", &a.a, &a.b, &a.id);
				a.cnt=cnt++;
				out[a.id].pb(a);
			}
		}
		
		rep(i, 0, in.size()+1){
			//cout << i << endl;
			int j=0;
			while(j<out[i].size()){
				//cout << out[i][j].a <<" " << out[i][j].b<< endl;
				ans[out[i][j].cnt]=query_tree(1, 1, N, out[i][j].a, out[i][j].b);
				j++;
			}
			if(i==in.size()) continue;
			update_tree(1, 1, N, in[i].k, in[i].v);
		}
		rep(i, 0, cnt){
			printf("%lld\n", ans[i]);
		}	
	}
	
	return 0;	
}



