// Author: Gustavo Policarpo
// Name: Blasted and Curious
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1797

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
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
typedef pair < int, int > ii;

inline int cmp( double x, double y = 0, double tol = EPS) 
{ 
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); 
}

struct ponto
{
	double x, y, disO;
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

int ccw(ponto p, ponto q, ponto r)
{
	return cmp( vec(p,q) % vec(p,r) );
}

double norma(vec u){ 
	return sqrt(u*u); 
}

vec projecao(vec a, vec b){
	return b * ((a*b) / (b*b)); 
}

bool entre(ponto r, ponto p, ponto s){ 
	return cmp(vec(p,s)%vec(p,r))==0 && 
	cmp(vec(p,r)*vec(p,s)) <= 0; 
}


double PTSeg(ponto p, ponto a, ponto b){ 
	ponto pp = a + projecao(vec(a,p), vec(a,b)); 
	if (entre(a,pp,b)) return norma(p-pp);
	else return min(norma(a-p), norma(b-p));
}

bool in(ponto a, ponto *b){
	if(a.x>=b[0].x && a.x<=b[3].x && a.y>=b[0].y && a.y<=b[3].y ) return true;
	return false;
}

int dx[]={-1, -1, 1, 1}, dy[]={-1, 1, -1, 1};
bool go(ponto last, double dl, ponto at, double da, double D){
	
	ponto a[4], b[4];
	rep(i, 0, 4){
		a[i] = ponto(last.x + dl/2.0*dx[i], last.y + dl/2.0*dy[i]);
		b[i] = ponto(at.x + da/2.0*dx[i], at.y + da/2.0*dy[i]);
	}
	
	rep(i, 0, 4) if(in(a[i], b)) return true;
	
	double dst=INF;
	rep(i, 0, 4){
		dst=min(dst, PTSeg(a[i], b[0], b[1]));
		dst=min(dst, PTSeg(a[i], b[0], b[2]));
		dst=min(dst, PTSeg(a[i], b[1], b[3]));
		dst=min(dst, PTSeg(a[i], b[2], b[3]));
		if(dst <= D) return true;
	}
	
	rep(i, 0, 4) swap(a[i], b[i]);
	
	rep(i, 0, 4){
		dst=min(dst, PTSeg(a[i], b[0], b[1]));
		dst=min(dst, PTSeg(a[i], b[0], b[2]));
		dst=min(dst, PTSeg(a[i], b[1], b[3]));
		dst=min(dst, PTSeg(a[i], b[2], b[3]));
		if(dst <= D) return true;
	}
	
	return false;
	
}

int main()
{
	
	int N, D;
	scanf("%d %d", &N, &D);
	
	ponto last, at; double dl, da;
	scanf("%lf %lf %lf", &last.x, &last.y, &dl);
	
	rep(i, 1, N){
		scanf("%lf %lf %lf", &at.x, &at.y, &da);
		
		if(!go(last, dl, at, da, D)){
			puts("OUCH");
			return 0;
		}
		
		last=at, dl=da;
	}
	
	puts("YEAH");
	
	return 0;
	
}
