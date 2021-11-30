// Author: Gustavo Policarpo
// Name: Lasers
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2104

#include <bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x);
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>*/

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
#define all(s) s.begin(), s.end()

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

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




#define EPS 1e-9
int sgn(double x){ 
	return (x > EPS) - (x < -EPS); 
}

#define vec(ini, fim) (fim - ini) 
struct PT{
	double x, y, z; 
	PT(){x = y = z = 0;} 
	PT(double x,double y, double z):x(x), y(y), z(z){} 
	PT operator + (PT q){return PT(x+q.x,y+q.y,z+q.z);} 
	PT operator - (PT q){return PT(x-q.x,y-q.y,z-q.z);} 
	PT operator * (double d){ return PT(x*d, y*d, z*d); } 
	PT operator / (double d){ return PT(x/d, y/d, z/d); } 
	double dist2() const { return x*x+y*y+z*z; }
	double dist() const{ return sqrt(dist2()); }
	bool operator == (const PT& a) const{ 
		return fabs(x - a.x) < EPS && fabs(y - a.y) < EPS && fabs(z - a.z) < EPS; 
	} 
};
		
double dot(PT A, PT B){ // produto escalar 
	return A.x*B.x + A.y*B.y + A.z*B.z; 
}

PT cross(PT A, PT B){ // produto vetorial 
	return PT (A.y*B.z-A.z*B.y, A.z*B.x-A.x*B.z, A.x*B.y-A.y*B.x ); 
}

struct line{ // reta definida por um ponto p e direcao v 
	PT p, v; line(){}; 
	line(PT p, PT v):p(p),v(v){ 
		assert(!(v == PT())); 
	}
	bool on(PT& pt) { 
		return cross(pt - p, v) == PT(); 
	} 
};

struct plane { 
	PT n; double d; plane() : d(0) {} 
	plane(PT p1, PT p2, PT p3) { 
		n = cross(p2 - p1, p3 - p1); d = -dot(n, p1); 
		assert(side(p1) == 0); 
		assert(side(p2) == 0); 
		assert(side(p3) == 0); 
	}
	int side(PT p) const { 
		return sgn(dot(n, p) + d); 
	} 
};

int cross( line l,  plane pl, PT &res ) { 
	double d = dot(pl.n, l.v); 
	if (sgn(d) == 0) { 
		return (pl.side(l.p) == 0) ? 2 : 0; 
	}
	double t = (-dot(pl.n, l.p) - pl.d) / d; 
	res = l.p + l.v * t; 
#ifdef DEBUG 
	assert(pl.side(res) == 0); 
#endif 
	return 1; 
}

inline int cmp( double x, double y = 0, double tol = EPS){
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

int sgn(ll x) { return x < 0 ? -1 : x > 0; }


struct point{
	double x, y;
	point(double x=0, double y=0): x(x), y(y){}
	point operator +(point q){ return point(x+q.x, y+q.y);}
	point operator -(point q){ return point(x-q.x, y-q.y);}
	point operator *(double t){ return point(x*t, y*t); }
	point operator /(double t){ return point(x/t, y/t); }
	point operator /(point q){ // divisao de num complexos
		return point(x*q.x+y*q.y, y*q.x-x*q.y)/q.norma2();
	}
	double norma2(){ return (*this)*(*this); } // |u|^2
	double operator *(point q){ return x*q.x+y*q.y; }
	double operator %(point q){ return x*q.y-y*q.x; }
	int cmp(point q) const{
	if(int t = ::cmp(x, q.x)) return t;
		return ::cmp(y, q.y);
	}
	bool operator == (point q) const{return cmp(q) == 0;};
	bool operator != (point q) const{return cmp(q) != 0;};
	bool operator < (point q) const{return cmp(q) < 0;};
};

int ccw(point p, point q, point r){
	return cmp(vec(p, q)%(vec(p, r)));
}

point pivot; 
bool radial_lt(point a, point b){ 
	int R = ccw(pivot, a, b); // verifica se A esta antes de B 
	if (R == 0) // pivot,a,b sao colineares 
	return (pivot-a)*(pivot-a) < (pivot-b)*(pivot-b); 
	else return (R == 1); // 1 se A vem antes de B, sentido ccw 
}

vector<point> convexhull(vector<point> &T){
	sort(T.begin(), T.end()); //ordena por x e por y 
	T.resize( unique( T.begin(), T.end() ) - T.begin() ); 
	int tam = 0, k, n = T.size(); 
	vector<point> U; // convex hull 
	int P0 = min_element(T.begin(), T.end() ) - T.begin(); 
	//nesse caso, pivot = ponto com menor x, depois menor y 
	pivot = T[P0]; swap(T[0], T[P0]); 
	sort(++T.begin(), T.end(), radial_lt); /*(1)*/
	for(k=n-2; k>=0 && ccw(T[0],T[n-1],T[k])==0; k--); 
	reverse((k+1)+all(T)); // troque <= para < para manter pontos colineares 
	for(int i = 0; i < n; i++){ 
		while (tam > 1 && ccw(U[tam-2], U[tam-1], T[i]) <= 0) 
			U.pop_back(), tam--; U.pb(T[i]); 
		tam++; 
	}
	return U; 
}

typedef vector<point> polygon;

double signedArea(polygon& T){
	double area = 0;
	int n = T.size();
	if (n < 3) return 0;
	rep(i, 0, n)
	area += T[i] % T[(i+1)%n];
	return (area/2.0);
}

double poly_area(polygon& T){
	return fabs(signedArea(T));
}

PT lz;
PT plat[1010];
plane terra;

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N;
	terra = plane(PT(-200, 0, 0), PT(200, 0, 0), PT(0, 200, 0));
	while(scanf("%d", &N) and N){
		
		vector <point> esf, pol;
		
		scanf("%lf %lf %lf", &lz.x, &lz.y, &lz.z);
		rep(i, 0, N){
			scanf("%lf %lf %lf", &plat[i].x, &plat[i].y, &plat[i].z);
			PT aux;
			cross(line(lz, plat[i]-lz), terra, aux);
			//cout << "hehe  ";
			//cout << aux.x << " " << aux.y << " " << aux.z << '\n';
			esf.pb(point(aux.x, aux.y));
		}
		
		pol = convexhull(esf);
		double ans = poly_area(pol);
		printf("%.2lf\n", ans);
		
	}
	
	
	return 0;
}

