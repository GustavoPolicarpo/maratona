// Author: Gustavo Policarpo
// Name: BST Operations I
// Level: 4
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1200

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
	char val;
	node() {}
	node(char v) : val(v), left(0), right(0) {};
};
vector <node> tree;
void inSert(int no, char val){
	if(tree.empty()){
		tree.pb(node(val));
		return;
	}
	if(val > tree[no].val){
		if(tree[no].right) inSert(tree[no].right, val);
		else{
			tree[no].right=tree.size();
			tree.pb(node(val));
		}
	}else{
		if(tree[no].left) inSert(tree[no].left, val);
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
	if(tree[no].left) prefixa(tree[no].left);
	if(tree[no].right) prefixa(tree[no].right);
}
void insfixa(int no){
	if(tree[no].left) insfixa(tree[no].left);
	if(yep) printf(" ");
	else yep=1;
	printf("%c", tree[no].val);
	if(tree[no].right) insfixa(tree[no].right);
}
void posfixa(int no){
	if(tree[no].left) posfixa(tree[no].left);
	if(tree[no].right) posfixa(tree[no].right);
	if(yep) printf(" ");
	else yep=1;
	printf("%c", tree[no].val);
}

int main()
{
	char s[20];
	set <char> has;
	while(gets(s)){
		yep=0;
		if(strcmp(s, "INFIXA") == 0) insfixa(0), printf("\n");
		else if(strcmp(s, "PREFIXA") == 0) prefixa(0), printf("\n");
		else if(strcmp(s, "POSFIXA") == 0) posfixa(0), printf("\n");
		else if(s[0]=='I') inSert(0, s[2]), has.insert(s[2]);
		else if(has.count(s[2])) printf("%c existe", s[2]), printf("\n");
		else printf("%c nao existe", s[2]), printf("\n");
	}

	return 0;
	
}
