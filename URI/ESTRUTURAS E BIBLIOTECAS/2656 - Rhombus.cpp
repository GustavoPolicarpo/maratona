// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Rhombus
// Nível: 5
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2656

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

void scanint(int &x){
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
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
int cnt = 0;

bool inRange(int x1, int x2, int y1, int y2, int a1, int a2, int b1, int b2){
	if(x2 < x1 || y2 < y1) return false;
	if(x2 < a1 || x1 > a2) return false;
	if(y2 < b1 || y1 > b2) return false;
	return true;
}

void update(int no, int x1, int x2, int y1, int y2, int a1, int a2, int b1, int b2, int val){
	if(no == cnt) tree[cnt++] = new_node();
	
	if(x1>=a1 && x2<=a2 && y1>=b1 && y2<=b2){
		tree[no].qt = val;
		return;
	}
	
	int f1=0, f2=0, f3=0, f4=0;
	if(inRange(x1, (x1+x2)/2, y1, (y1+y2)/2, a1, a2, b1, b2)){
		if(!tree[no].f1) tree[no].f1 = cnt;
		update(tree[no].f1, x1, (x1+x2)/2, y1, (y1+y2)/2, a1, a2, b1, b2, val);
	}
	if(inRange(x1, (x1+x2)/2, (y1+y2)/2+1, y2, a1, a2, b1, b2)){
		if(!tree[no].f2) tree[no].f2 = cnt;
		update(tree[no].f2, x1, (x1+x2)/2, (y1+y2)/2+1, y2, a1, a2, b1, b2, val);
	}
	if(inRange((x1+x2)/2+1, x2, y1, (y1+y2)/2, a1, a2, b1, b2)){
		if(!tree[no].f3) tree[no].f3 = cnt;
		update(tree[no].f3, (x1+x2)/2+1, x2, y1, (y1+y2)/2, a1, a2, b1, b2, val);
	}
	if(inRange((x1+x2)/2+1, x2, (y1+y2)/2+1, y2, a1, a2, b1, b2)){
		if(!tree[no].f4) tree[no].f4 = cnt;
		update(tree[no].f4, (x1+x2)/2+1, x2, (y1+y2)/2+1, y2, a1, a2, b1, b2, val);
	}
	
	if(tree[no].f1) f1=tree[tree[no].f1].qt;
	if(tree[no].f2) f2=tree[tree[no].f2].qt;
	if(tree[no].f3) f3=tree[tree[no].f3].qt;
	if(tree[no].f4) f4=tree[tree[no].f4].qt;
	
	tree[no].qt=f1+f2+f3+f4;
}

int query(int no, int x1, int x2, int y1, int y2, int a1, int a2, int b1, int b2){
	//cout << no << " " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << a1 << " " << b1 << " " << a2 << " " << b2 << "\n";
	if(!inRange(x1, x2, y1, y2, a1, a2, b1, b2) || no>=cnt || tree[no].qt==0) return 0;
	
	if(x1>=a1 && x2<=a2 && y1>=b1 && y2<=b2) return tree[no].qt;
	
	int f1=0, f2=0, f3=0, f4=0;
	if(tree[no].f1) f1 = query(tree[no].f1, x1, (x1+x2)/2, y1, (y1+y2)/2, a1, a2, b1, b2);
	if(tree[no].f2) f2 = query(tree[no].f2, x1, (x1+x2)/2, (y1+y2)/2+1, y2, a1, a2, b1, b2);
	if(tree[no].f3) f3 = query(tree[no].f3, (x1+x2)/2+1, x2, y1, (y1+y2)/2, a1, a2, b1, b2);
	if(tree[no].f4) f4 = query(tree[no].f4, (x1+x2)/2+1, x2, (y1+y2)/2+1, y2, a1, a2, b1, b2);
	
	return f1+f2+f3+f4;
	
}

void erase(){
	tree.clear();
	vector <node> xua;
	swap(tree, xua);
	tree.resize(1000010);
	cnt = 0;
}

map<ii, int> mapa;

int main(){
	
	int Q; scanint(Q); erase();
	int op, x, y, d;
	
	while(Q--){
		scanint(op), scanint(x), scanint(y);
		/*op = rand()%3 + 1;
		x = rand()%100001;
		y = rand()%100001;
		*/
		int xx=x+y+1e5;
		int yy=x-y+1e5;
		
		if(op==1){
			if(mapa[ii(xx, yy)]) continue;
			mapa[ii(xx, yy)] = 1;
			update(0, 0, 300000, 0, 300000, xx, xx, yy, yy, 1);
		}else if(op==2){
			if(!mapa[ii(xx, yy)]) continue;
			mapa[ii(xx, yy)] = 0;
			update(0, 0, 300000, 0, 300000, xx, xx, yy, yy, 0);
		}else if(op==3){
			scanint(d);
			//d = rand()%100000;
			int ans = query(0, 0, 300000, 0, 300000, max(xx-d, 0), min(xx+d, 300000), max(yy-d, 0), min(yy+d, 300000));
			printf("%d\n", ans);
		}
	}
	
	return 0;
}
