// Author: Gustavo Policarpo
// Name: Level Order Tree Traversal
// Level: 3
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1466

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
typedef pair < int, int > ii;

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

struct node{
	int left, right;
	int val;
	node() {}
	node(int v) : val(v), left(-1), right(-1) {};
};
vector <node> tree;
void inSert(int no, int val){
	if(tree.empty()){
		tree.pb(node(val));
		return;
	}
	if(val > tree[no].val){
		if(tree[no].right!=-1) inSert(tree[no].right, val);
		else{
			tree[no].right=tree.size();
			tree.pb(node(val));
		}
	}else{
		if(tree[no].left!=-1) inSert(tree[no].left, val);
		else{
			tree[no].left=tree.size();
			tree.pb(node(val));
		}
	}
	return;
}
int yep;
void prefixa(int no){
	if(yep) printf(" ");
	else yep=1;
	printf("%c", tree[no].val);
	if(tree[no].left!=-1) prefixa(tree[no].left);
	if(tree[no].right!=-1) prefixa(tree[no].right);
}
void insfixa(int no){
	if(tree[no].left!=-1) insfixa(tree[no].left);
	if(yep) printf(" ");
	else yep=1;
	printf("%c", tree[no].val);
	if(tree[no].right!=-1) insfixa(tree[no].right);
}
void posfixa(int no){
	if(tree[no].left!=-1) posfixa(tree[no].left);
	if(tree[no].right!=-1) posfixa(tree[no].right);
	if(yep) printf(" ");
	else yep=1;
	printf("%c", tree[no].val);
}
void largura(int no){
	queue <int> q;
	q.push(no);
	
	int yep=0;
	while(!q.empty()){
		if(yep) printf(" ");
		else yep=1;
		
		no=q.front(); q.pop();
		printf("%d", tree[no].val);
		
		if(tree[no].left!=-1) q.push(tree[no].left);
		if(tree[no].right!=-1) q.push(tree[no].right);
	}
	printf("\n");
}

int main()
{
	int T, N, u; scanint(T);
	rep(z, 1, T+1){
		scanint(N);
		tree.clear();
		
		scanint(u);
		tree.pb(node(u));
		
		rep(i, 1, N){
			scanint(u);
			inSert(0, u);
		}
		
		printf("Case %d:\n", z);
		largura(0);
		printf("\n");
	}

	return 0;
	
}
