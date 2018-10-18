// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Regata de Cientistas
// Nível: 7
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1370

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;

#define EPS 1e-9

inline int cmp( double x, double y = 0, double tol = EPS){
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

struct point{
	double x, y;
	point(){}
	point(double x, double y) :x(x), y(y) {}
	point (point a, point b) { x=(b.x-a.x); y=(b.y-a.y); }
	point operator +(point q){ return point(x+q.x, y+q.y); }
	point operator -(point q){ return point(x-q.x, y-q.y); }
	point operator /(double t){ return point(x/t, y/t); }
	double operator %(point q){ return x*q.y-y*q.x; }
	void read() { cin >> x >> y; }
	void debug() { cout << "x: " << x << " y: " << y << '\n'; }
};

#define vec(a, b) (b-a)
typedef pair<point, point> ii;

int ccw(point p, point q, point r){
	return cmp(vec(p, q)%(vec(p, r)));
}

bool is_in(double l, double r, double x){
	if (l > r) swap(l, r);
	return (l <= x + EPS) && (x - EPS <= r);
}
bool between(point p, point a, point b) {
	if (ccw(p,a,b) != 0) return false;
	else return is_in(a.x, b.x, p.x) && is_in(a.y, b.y, p.x);
}

bool seg_intersect(point a, point b, point c, point d){
	int d1, d2, d3, d4;
	d1 = ccw(c, a, d); d2 = ccw(c, b, d);
	d3 = ccw(a, c, b); d4 = ccw(a, d, b);
	if (d1*d2 == -1 && d3*d4 == -1) return true;
	if (d1 == 0 && between(c, a, d)) return true;
	if (d2 == 0 && between(c, b, d)) return true;
	if (d3 == 0 && between(a, c, b)) return true;
	if (d4 == 0 && between(a, d, b)) return true;
	return false;
}

vector <ii> seg;
double dist[333][333];

bool check(point a, point b, int i, int j){
	rep(k, 1, seg.size()) if(k!=i && k!=j && seg_intersect(a, b, seg[k].F, seg[k].S)) return false;
	return true;
}

double distPt(point a, point b){
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int main(){
	
	point a, b; int n, t;
	while(42){
		a.read(), b.read(); cin >> n;
		
		if(!a.x && !a.y && !b.x && !b.y && !n) break;
		seg.clear();
		t = n*2+2;
		rep(i, 0, t+2) rep(j, 0, t+2) dist[i][j] = (i==j ? 0 : 1e32);
		
		seg.pb(ii(a, b));
		rep(i, 0, n) a.read(), b.read(), seg.pb(ii(a, b));
		
		rep(i, 0, seg.size()){
			rep(j, 0, seg.size()){
				if(check(seg[i].F, seg[j].F, i, j)) dist[i*2][j*2] = distPt(seg[i].F, seg[j].F);
				if(check(seg[i].F, seg[j].S, i, j)) dist[i*2][j*2+1] = distPt(seg[i].F, seg[j].S);
				if(check(seg[i].S, seg[j].F, i, j)) dist[i*2+1][j*2] = distPt(seg[i].S, seg[j].F);
				if(check(seg[i].S, seg[j].S, i, j)) dist[i*2+1][j*2+1] = distPt(seg[i].S, seg[j].S);
			}
		}
		
		rep(k, 0, t+2)
		rep(i, 0, t+2)
		rep(j, 0, t+2)
			dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	
		printf("%.2lf\n", dist[0][1]);
		
	}
	
	return 0;
} 
