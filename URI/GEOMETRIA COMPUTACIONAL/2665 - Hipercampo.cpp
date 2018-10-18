// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Hipercampo
// Nível: 5
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2665

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const ll mod = 1e9+7;
#define EPS 1e-9

inline int cmp( double x, double y = 0, double tol = EPS){ 
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); 
}

struct point{
	double x, y;
	point(double x=0, double y=0): x(x), y(y){}
	point operator -(point q){ return point(x-q.x, y-q.y);}
	double operator %(point q){ return x*q.y-y*q.x; }
};

#define vec(a, b) (b-a)
int ccw(point p, point q, point r){
	return cmp(vec(p, q)%(vec(q, r)));
}

int N, pd[101];
point A, B, n[101];

int solve(int x){
	if(pd[x]!=-1) return pd[x];
	pd[x] = 0;
	rep(i, 0, N){
		if(ccw(A, n[x], n[i])==-1 && ccw(B, n[x], n[i])==1)
			pd[x] = max(pd[x], solve(i)+1);
	}
	return pd[x];
}

int main(){
	
	A.y = B.y = 0;
	cin >> N >> A.x >> B.x;
	rep(i, 0, N) cin >> n[i].x >> n[i].y;
	
	int ans = 0; memset(pd, -1, sizeof pd);
	rep(i, 0, N) ans = max(ans, solve(i)+1);
	
	cout << ans << '\n';
	
	return 0;
}
