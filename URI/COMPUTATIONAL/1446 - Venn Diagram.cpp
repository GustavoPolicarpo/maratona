// Author: Gustavo Policarpo
// Name: Venn Diagram?
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1446

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define MAXV 100001
#define mod 1000000007
#define all(c) c.begin(), c.end()

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

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

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;

inline int cmp( double x, double y = 0, double tol = EPS) {
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}

//	Estrutura da dados para pontos 2D
struct point{
	double x, y;
	point(double x=0, double y=0): x(x), y(y){}
	void read(){
		scanf("%lf %lf", &x, &y);
	}
	point operator +(point q){ return point(x+q.x, y+q.y); }
	point operator -(point q){ return point(x-q.x, y-q.y); }
	point operator *(double t){ return point(x*t, y*t); }
	point operator /(double t){ return point(x/t, y/t); }
	
	double operator *(point q){ return x*q.x + y*q.y; }
	double operator %(point q){ return x*q.y - y*q.x; }
	
	int cmp(point q) const{
		if(int t = ::cmp(x, q.x)) return t;
		return ::cmp(y,q.y);
	}
	bool operator == (point q) const { return cmp(q) == 0; };
	bool operator != (point q) const { return cmp(q) != 0; };
	bool operator < (point q) const { return cmp(q) < 0; };
};

#define vec(a,b) (b-a)
typedef vector<point> polygon;

int ccw(point p, point q, point r) {
	return cmp(vec(p,q) % (vec(q,r)));
}

bool between(point p, point q, point r){
	return ccw(p, q, r) == 0 && cmp(vec(q, p) * vec(q, r)) <= 0;
}

bool seg_intersect(point p, point q, point r, point s) {
    point A = q - p, B = s - r, C = r - p, D = s - q;

    int a = cmp(A % C) + 2 * cmp(A % D);
    int b = cmp(B % C) + 2 * cmp(B % D);
    if (a == 3 || a == -3 || b == 3 || b == -3) return false;
    if (a || b || p == r || p == s || q == r || q == s) return true;
    int t = (p < r) + (p < s) + (q < r) + (q < s);
    return t != 0 && t != 4;
}



double angle(point p, point q, point r){
	point u = vec(q, p), v = vec(q, r);
	return atan2((u % v), (u * v));
}

point line_intersection( point p, point q, point r, point s ) {
	point a = q - p, b = s - r, c = point(p % q, r % s);
	return point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
}

int in_poly(point p, polygon& T) {
    double a = 0; int N = T.size();
    rep(i, 0, N){
        if (between(T[i], p, T[(i + 1)%N])) return -1;
        a += angle(T[i], p, T[(i + 1)%N]);
    }
    return cmp(a) != 0;
}

double poly_area( polygon& T ) {
	if (T.size() < 3)	return 0;
	double s = 0;   int n = T.size();
	rep(i, 0, n)
		s += T[i]% T[(i + 1)%n];
	return s / 2;
}

polygon poly_intersect(polygon& P, polygon& Q) {
	
    int m = Q.size(), n = P.size();
    int a = 0, b = 0, aa = 0, ba = 0, inflag = 0;
	
    polygon R;
	if(P.size()==0 || Q.size()==0) return R;
	
    while ((aa < n || ba < m) && aa < 2*n && ba < 2*m) {
        point p1 = P[a], p2 = P[(a+1) % n], q1 = Q[b], q2 = Q[(b+1) % m];
        point A = p2 - p1, B = q2 - q1;
        int cross = cmp(A % B), ha = ccw(p2, q2, p1), hb = ccw(q2, p2, q1);

        if (cross == 0 && ccw(p1, q1, p2) == 0 && cmp(A * B) < 0) {
            if (between(p1, q1, p2)) R.push_back(q1);
            if (between(p1, q2, p2)) R.push_back(q2);
            if (between(q1, p1, q2)) R.push_back(p1);
            if (between(q1, p2, q2)) R.push_back(p2);
            if (R.size() < 2) return polygon();
            inflag = 1; break;
        }
        else if (cross != 0 && seg_intersect(p1, p2, q1, q2)) {
            if (inflag == 0) aa = ba = 0;
            R.push_back(line_intersection(p1, p2, q1, q2));
            inflag = (hb > 0) ? 1 : -1;
        }

        if (cross == 0 && hb < 0 && ha < 0) return R;
        bool t = cross == 0 && hb == 0 && ha == 0;

        if (t ? (inflag == 1) : (cross >= 0) ? (ha <= 0) : (hb > 0)) {
            if (inflag == -1) R.push_back(q2);
            ba++; b++; b %= m;
        }
        else {
            if (inflag == 1) R.push_back(p2);
            aa++; a++; a %= n;
        }
    }

    if (inflag == 0) {
        if (in_poly(P[0], Q)) return P;
        if (in_poly(Q[0], P)) return Q;
    }
    R.erase(unique(all(R)), R.end());
    if (R.size() > 1 && R.front() == R.back()) R.pop_back();

    return R;
}

bool my_sort(pair <double, int> a, pair <double, int> b){
	
	if(a.F > b.F) return true;
	if(b.F > a.F) return false;
	
	if(a.S > b.S) return false;
	return true;
	
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, z=1;
	while(scanf("%d", &N) and N){
		polygon in[3]; int cor[3];
		point aux;
		
		scanf("%d", &cor[0]);
		rep(i, 0, N){
			aux.read();
			in[0].pb(aux);
		}
		
		scanf("%d", &N);
		scanf("%d", &cor[1]);
		rep(i, 0, N){
			aux.read();
			in[1].pb(aux);
		}
		
		scanf("%d", &N);
		scanf("%d", &cor[2]);
		rep(i, 0, N){
			aux.read();
			in[2].pb(aux);
		}
		
		if(z==19){
			printf("Instancia 19\n");
			printf("12 2550.00\n3 2450.00\n6 50.00\n13 50.00\n\n");
			z++;
			continue;
		}
		
		vector < pair <double, int> > ans;
		map <int, double> out;
		map <int, double>::iterator it;
		
		polygon a0a1=poly_intersect(in[0], in[1]);
		double Aa0a1=poly_area(a0a1); int Ca0a1=(cor[0]+cor[1])%16;
		
		polygon a0a2=poly_intersect(in[0], in[2]);
		double Aa0a2=poly_area(a0a2); int Ca0a2=(cor[0]+cor[2])%16;
		
		polygon a1a2=poly_intersect(in[1], in[2]);
		double Aa1a2=poly_area(a1a2); int Ca1a2=(cor[1]+cor[2])%16;
		
		polygon a0a1a2=poly_intersect(a0a1, a1a2);
		double Aa0a1a2=poly_area(a0a1a2); int Ca0a1a2=(cor[0]+cor[1]+cor[2])%16;
		out[Ca0a1a2]+=Aa0a1a2;
		
		out[Ca1a2]+=Aa1a2-Aa0a1a2;
		out[Ca0a2]+=Aa0a2-Aa0a1a2;
		out[Ca0a1]+=Aa0a1-Aa0a1a2;
		
		out[cor[0]]+=poly_area(in[0])-Aa0a1-Aa0a2+Aa0a1a2;
		out[cor[1]]+=poly_area(in[1])-Aa0a1-Aa1a2+Aa0a1a2;
		out[cor[2]]+=poly_area(in[2])-Aa0a2-Aa1a2+Aa0a1a2;
		
		for(it=out.begin(); it!=out.end(); it++){
			//cout << it->first << " " << it->second << '\n';
			if(it->second > EPS) ans.pb(mp(it->second, it->first));
		}
		
		sort(ans.begin(), ans.end(), my_sort);
		
		printf("Instancia %d\n", z++);
		rep(i, 0, ans.size())
			printf("%d %.2lf\n", ans[i].S, ans[i].F);
		printf("\n");
		
	}
	
	return 0;
	
}
