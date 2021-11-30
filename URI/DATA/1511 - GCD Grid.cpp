// Author: Gustavo Policarpo
// Name: GCD Grid
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1511

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


typedef int value_type;

vector<value_type> tree;

bool inRange(size_t qx1,size_t qx2,size_t qy1,size_t qy2,size_t nx1,size_t nx2,size_t ny1,size_t ny2)
{
	if(nx2<nx1||ny2<ny1)   // node is invalid.
		return false;
	if(qx2<nx1||qx1>nx2)   // x is out of bounds
		return false;
	if(qy2<ny1||qy1>ny2)   // y is out of bounds
		return false;
	return true;
}

inline size_t child(size_t node,size_t number)
{
	return node*4+number;
}

void update(size_t qx1,size_t qx2,size_t qy1,size_t qy2,size_t nx1,size_t nx2,size_t ny1,size_t ny2, size_t node, value_type &value)
{
	if(!inRange(qx1,qx2,qy1,qy2,nx1,nx2,ny1,ny2))
		return;
	else if(nx1>=qx1&&nx2<=qx2&&ny1>=qy1&&ny2<=qy2&&nx1==nx2&&ny1==ny2) // node is within query
		tree[node]=value;
	else
	{
		update(qx1,qx2,qy1,qy2,	nx1,(nx1+nx2)/2,ny1,(ny2+ny1)/2,        child(node,1), value);
		update(qx1,qx2,qy1,qy2,	nx1, (nx1+nx2)/2, (ny1+ny2)/2+1, ny2,   child(node,2), value);
		update(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2,	ny1, (ny2+ny1)/2,   child(node,3), value);
		update(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2, (ny1+ny2)/2+1, ny2, child(node,4), value);
		value_type LL=tree[child(node,1)];
		value_type LR=tree[child(node,2)];
		value_type RL=tree[child(node,3)];
		value_type RR=tree[child(node,4)];
		tree[node]=__gcd(LL, __gcd(LR, __gcd(RL, RR)));
	}
}

value_type query (size_t qx1,size_t qx2,size_t qy1,size_t qy2,size_t nx1,size_t nx2,size_t ny1,size_t ny2,size_t node)
{
	if(!inRange(qx1,qx2,qy1,qy2,nx1,nx2,ny1,ny2))
		return 0;
	else if(nx1>=qx1&&nx2<=qx2&&ny1>=qy1&&ny2<=qy2)
		return tree[node];
	else
	{
		value_type LL=query(qx1,qx2,qy1,qy2, nx1,(nx1+nx2)/2, ny1,(ny2+ny1)/2,       child(node,1));
		value_type LR=query(qx1,qx2,qy1,qy2, nx1, (nx1+nx2)/2, (ny1+ny2)/2+1, ny2,   child(node,2));
		value_type RL=query(qx1,qx2,qy1,qy2, (nx1+nx2)/2+1, nx2, ny1, (ny2+ny1)/2,   child(node,3));
		value_type RR=query(qx1,qx2,qy1,qy2, (nx1+nx2)/2+1, nx2, (ny1+ny2)/2+1, ny2, child(node,4));
		return __gcd(LL, __gcd(LR, __gcd(RL, RR)));
	}
}

void erase(){
	vector <value_type> aux;
	swap(aux, tree);
	tree.resize(4*2002*2002);
}
int main()
{
	ios_base::sync_with_stdio(false);
	
	int Q;
	
	while(cin >> Q){
		
		if(!Q) break;
		
		erase();
		string s; int xx, yy, d;
		
		while(Q--){
			cin >> s >> xx >> yy >> d;
			
			int x=xx+yy+1000;
			int y=xx-yy+1000;
			
			if(s[0]=='S'){
				update(x,x,y,y,0,2002,0,2002,0,d);
			}else{
				int ans=query(max(x-d, 0), min(x+d, 2002),max(y-d, 0),min(y+d, 2002),0,2002,0,2002,0);
				printf("%d\n", ans);
			}
			
		}
		
	}
	
	return 0;
}
