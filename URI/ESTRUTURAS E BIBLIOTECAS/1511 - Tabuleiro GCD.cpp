// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tabuleiro GCD
// Nível: 8
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1511

#include <bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x);

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

//typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void scanint(int &x){
    register int ccc = gc(); x = 0; int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

struct node{
	int qt;
	int f1, f2, f3, f4;
};

node new_node(){
	node ret;
	ret.qt=ret.f1=ret.f2=ret.f3=ret.f4=0;
	return ret;
}

vector <node> tree;

bool inRange(int x1, int x2, int y1, int y2, int a1, int a2, int b1, int b2){
	if(x2 < x1 || y2 < y1) return false;
	if(x2 < a1 || x1 > a2) return false;
	if(y2 < b1 || y1 > b2) return false;
	return true;
}

void update(int no, int x1, int x2, int y1, int y2, int a1, int a2, int b1, int b2, int val){
	if(no == tree.size()) tree.pb(new_node());
	
	if(x1>=a1 && x2<=a2 && y1>=b1 && y2<=b2){
		tree[no].qt = val;
		return;
	}
	
	int f1=0, f2=0, f3=0, f4=0;
	if(inRange(x1, (x1+x2)/2, y1, (y1+y2)/2, a1, a2, b1, b2)){
		if(!tree[no].f1) tree[no].f1 = tree.size();
		update(tree[no].f1, x1, (x1+x2)/2, y1, (y1+y2)/2, a1, a2, b1, b2, val);
	}
	if(inRange(x1, (x1+x2)/2, (y1+y2)/2+1, y2, a1, a2, b1, b2)){
		if(!tree[no].f2) tree[no].f2 = tree.size();
		update(tree[no].f2, x1, (x1+x2)/2, (y1+y2)/2+1, y2, a1, a2, b1, b2, val);
	}
	if(inRange((x1+x2)/2+1, x2, y1, (y1+y2)/2, a1, a2, b1, b2)){
		if(!tree[no].f3) tree[no].f3 = tree.size();
		update(tree[no].f3, (x1+x2)/2+1, x2, y1, (y1+y2)/2, a1, a2, b1, b2, val);
	}
	if(inRange((x1+x2)/2+1, x2, (y1+y2)/2+1, y2, a1, a2, b1, b2)){
		if(!tree[no].f4) tree[no].f4 = tree.size();
		update(tree[no].f4, (x1+x2)/2+1, x2, (y1+y2)/2+1, y2, a1, a2, b1, b2, val);
	}
	
	if(tree[no].f1) f1=tree[tree[no].f1].qt;
	if(tree[no].f2) f2=tree[tree[no].f2].qt;
	if(tree[no].f3) f3=tree[tree[no].f3].qt;
	if(tree[no].f4) f4=tree[tree[no].f4].qt;
	
	tree[no].qt = __gcd(f1, __gcd(f2, __gcd(f3, f4)));
}

int query(int no, int x1, int x2, int y1, int y2, int a1, int a2, int b1, int b2){
	//cout << no << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << a1 << " " << b1 << " " << a2 << " " << b2 << "\n";
	if(!inRange(x1, x2, y1, y2, a1, a2, b1, b2) || no>=tree.size()) return 0;
	
	if(x1>=a1 && x2<=a2 && y1>=b1 && y2<=b2) return tree[no].qt;
	
	int f1=0, f2=0, f3=0, f4=0;
	if(tree[no].f1) f1 = query(tree[no].f1, x1, (x1+x2)/2, y1, (y1+y2)/2, a1, a2, b1, b2);
	if(tree[no].f2) f2 = query(tree[no].f2, x1, (x1+x2)/2, (y1+y2)/2+1, y2, a1, a2, b1, b2);
	if(tree[no].f3) f3 = query(tree[no].f3, (x1+x2)/2+1, x2, y1, (y1+y2)/2, a1, a2, b1, b2);
	if(tree[no].f4) f4 = query(tree[no].f4, (x1+x2)/2+1, x2, (y1+y2)/2+1, y2, a1, a2, b1, b2);
	
	return __gcd(f1, __gcd(f2, __gcd(f3, f4)));
	
}

void erase(){
	tree.clear();
	vector <node> xua;
	swap(tree, xua);
}

int main()
{
	
	int Q;
	
	
	while(scanf("%d", &Q)!=EOF){
		
		if(!Q) break; erase();
		
		char s[20]; int xx, yy, d;
		
		while(Q--){
			scanf("%s %d %d %d", s, &xx, &yy, &d);
			
			int x=xx+yy+1000;
			int y=xx-yy+1000;
			
			if(s[0]=='S'){
				update(0, 0, 2002, 0, 2002, x, x, y, y, d);
			}else{
				int ans = query(0, 0, 2002, 0, 2002, max(x-d, 0), min(x+d, 2002),max(y-d, 0),min(y+d, 2002));
				printf("%d\n", ans);
			}
			
		}
		
	}
	
	return 0;
}
