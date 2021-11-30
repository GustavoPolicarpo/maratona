// Author: Gustavo Policarpo
// Name: Nota Cortada
// Level: 1
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3049

#include <iostream>
#include <iomanip>
#include <vector>	
#include <algorithm>
#include <cmath>
#include <cstring>

//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define REP(i,a,b) for( int i = (int) a; i <= (int) b; i++ )
#define PER(i,a,b) for( int i = (int) a; i >= (int) b; i-- )
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugPP(a) debug2(a.x, a.y)
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
 
using namespace std;
 
typedef long long int ll;
typedef pair <int, int> ii;
const int MAX = 2e3+3;
const int mod = 1e9+7;
const int MAXN = 1e7 + 5;
const ll LINF = 1LL << 52;

const double EPS = 1e-9;

inline int cmp (double x, double y = 0, double tol = EPS){
	return ( (x <= y+tol) ? (x+tol < y) ? -1 : 0 : 1);
}

struct point{
	double x, y;
	point(double x=0, double y=0) : x(x), y(y) {}
	point operator + (point q) { return point(x+q.x, y+q.y); }
	point operator - (point q) { return point(x-q.x, y-q.y); }
	
	int cmp(point q) const {
		if(int t = ::cmp(x, q.x)) return t;
		return ::cmp(y, q.y);
	}
	
	bool operator == (point q) const { return cmp(q) == 0; }
	bool operator < (point q) const { return cmp(q) < 0; }
};

#define vec(a, b) b-a

double dot(point a, point b){
	return a.x*b.x + a.y*b.y;
}

double cross(point a, point b){
	return a.x*b.y - a.y*b.x;
}

int ccw(point p, point q, point r){
	return cmp(cross(vec(p, q), vec(p, r)));
}

double abs(point u){
	return sqrt(dot(u, u));
}

double signedArea(vector <point> T){
	double area = 0.0;
	if(T.size() < 3) return 0;
	rep(i, 0, T.size()){
		area += cross(T[i], T[(i+1)%T.size()]);
	}
	return area/2.0;
}

double poly_area(vector <point> T){
	return fabs(signedArea(T));
}

point pivot;
bool radial_lt(point a, point b){
	int R = ccw(pivot, a, b);
	if(R==0) return abs(vec(a, pivot)) < abs(vec(b, pivot));
	return (R==1);
}


int findQuadrant(point aa){
	if(aa.x>=0 && aa.y>=0) return 1;
	if(aa.x<=0 && aa.y>=0) return 2;
	if(aa.x<=0 && aa.y<=0) return 3;
	return 4;
}

bool radial(point a, point b){
	point aa = a-pivot, bb = b-pivot;
	int qa = findQuadrant(aa);
	int qb = findQuadrant(bb);
	if(qa!=qb) return qa < qb;
	return radial_lt(a, b);
}

vector <point> convexHull(vector <point> &T){
	sort(T.begin(), T.end());
	T.resize( unique(T.begin(), T.end()) - T.begin() );
	
	vector <point> U;
	
	int idx = min_element(T.begin(), T.end()) - T.begin();
	swap(T[0], T[idx]);
	pivot = T[0];
	sort(++T.begin(), T.end(), radial_lt);
	
	int tam = 0, n = T.size();
	int k; for(k=n-2; k>=0 && ccw(T[0], T[n-1], T[k])==0; k--) ;
	reverse((k+1)+T.begin(), T.end());
	
	for(int i=0; i<T.size(); i++){
		while(tam > 1 && ccw(U[tam-2], U[tam-1], T[i]) <= 0)
			U.pop_back(), tam--;
		U.pb(T[i]), tam++;
	}
	
	return U;
}

vector <point> bands;
int N; point aux;
int cnt, mark[202][202];
int pd[202][202];

int solve(int l2, int l1){
	int &ret = pd[l2][l1];
	if(mark[l2][l1]==cnt) return ret;
	mark[l2][l1] = cnt; ret = 0;
	
	rep(i, l1+1, bands.size()){
		int dir = ccw(bands[l2], bands[l1], bands[i]);
		if(dir==1){
			ret = max(ret, solve(l1, i)+1);
		}
	}
	
	return ret;
}

int main(){
	
	int B, T;
	cin >> B >> T;
	
	T = 160 - T;
	
	if(B==T) puts("0");
	else if(B > T) puts("1");
	else puts("2");

	
	return 0;
}
