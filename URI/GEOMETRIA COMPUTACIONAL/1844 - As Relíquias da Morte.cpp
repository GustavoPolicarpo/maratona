// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: As Relíquias da Morte
// Nível: 6
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1844

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define ALL(c) c.begin(), c.end() 
#define SORT(c) sort(ALL(c)) 
#define UNIQUE(c) { SORT(c); (c).resize( unique(ALL(c))-c.begin() ); }

#define INF 0x3F3F3F3F
#define MAXV 100001

const double EPS = 1e-9;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, ii > iii;

inline int cmp( double x, double y = 0, double tol = EPS) 
{ 
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); 
}

struct ponto
{
	double x, y;
	ponto() {}
	ponto(double x, double y) :x(x), y(y) {}
	ponto (ponto a, ponto b){
		x=(b.x-a.x); y=(b.y-a.y);
	}
	ponto operator +(ponto q){ return ponto(x+q.x, y+q.y); }
	ponto operator -(ponto q){ return ponto(x-q.x, y-q.y); }
	ponto operator *(double t){ return ponto(x*t, y*t); }
	ponto operator /(double t){ return ponto(x/t, y/t); }
	
	int cmp(ponto q) const{
		if(int t = ::cmp(x, q.x)) return t;
		return ::cmp(y,q.y);
	}
	bool operator == (ponto q) const { return cmp(q) == 0; };
	bool operator != (ponto q) const { return cmp(q) != 0; };
	bool operator < (ponto q) const { return cmp(q) < 0; };
	
	double operator *(ponto q){ return x*q.x + y*q.y; }
	double operator %(ponto q){ return x*q.y - y*q.x; }
};

typedef ponto vec;
typedef vector<ponto> poligono;

double norma(vec u) {
	return sqrt(u*u); }
	
int ccw(ponto p, ponto q, ponto r)
{
	return cmp( vec(p,q) % vec(p,r) );
}
vec projecao(vec a, vec b)
{
	return b * ((a*b) / (b*b));
}

int pset[100000001];
vector < iii > edg;

void init(int n)
{
	rep(i, 0, n+1)
		pset[i]=i;	
}

int findset(int x)
{
	if(x!=pset[x])
		pset[x]=findset(pset[x]);
	return pset[x];
}


void unionset(int x, int y)
{
	x=findset(x); y=findset(y);
	if(x==y) return;
	pset[x]=y;
}

bool sameset(int x, int y)
{
	return findset(x)==findset(y);
}

bool entre(ponto r, ponto p, ponto s)
{
	return cmp(vec(p,s)%vec(p,r))==0 &&
	cmp(vec(p,r)*vec(p,s)) <=0;
}

double PTSeg(ponto p, ponto a, ponto b)
{
	ponto pp= a + projecao(vec(a,p),vec(a,b));
	if(entre(a,pp,b)) return norma(p-pp);
	else return min(norma(a-p), norma(b-p));
}

bool intersect_seg(ponto a, ponto b, ponto c, ponto d)
{
	int d1, d2, d3, d4;
	d1 = ccw(a, c, d);		d2 = ccw(b, c, d);
	d3 = ccw(c, a, b);		d4 = ccw(d, a, b);
	
	if(d1*d2==-1 && d3*d4==-1) return true;
	if(d1==0 && entre(c,a,d)) return true;
	if(d2==0 && entre(c,b,d)) return true;
	if(d3==0 && entre(a,c,b)) return true;
	if(d4==0 && entre(a,d,b)) return true;
	
	return false;	
}
int main()
{
	int N; cin >> N;
	int xa, xb, ya, yb;
	
	ponto rel[2][N+1];
	rep(i, 0, N){
		scanf("%d %d %d %d", &xa, &ya, &xb, &yb);
		rel[0][i].x=xa; rel[0][i].y=ya;
		rel[1][i].x=xb; rel[1][i].y=yb;
	}
	rep(i, 0, N){
		rep(j, 0, N){
			if(i==j) continue;
			if(intersect_seg(rel[0][i],rel[1][i],rel[0][j],rel[1][j])){
				edg.pb(mp(0, ii(i, j)));
				edg.pb(mp(0, ii(j, i)));
				continue;
			}	
			edg.pb(mp(PTSeg(rel[0][i],rel[0][j],rel[1][j]),ii(i,j)));
			edg.pb(mp(PTSeg(rel[1][i],rel[0][j],rel[1][j]),ii(i,j)));
		}
	}
	
	sort(edg.begin(), edg.end());
	
	init(edg.size());
	
	double mst=0;
	rep(i, 0, edg.size()){
		double c=edg[i].F;
		int a=edg[i].S.F;
		int b=edg[i].S.S;
		
		if(!sameset(a, b)){
			unionset(a,b);
			mst+=c;
		}
	}
	long int out = ceil(mst);
	cout << out	<< endl;
	edg.clear();
	

return 0;
}
