// Author: Gustavo Policarpo
// Name: Shrinking Polygons Kit
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2245

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

#define MAXV 100001



typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, ii > iii;
const double EPS = 1e-9, INF=ll(1)<<60;

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
int ccw(ponto p, ponto q, ponto r)
{
	return cmp( vec(p,q) % vec(p,r) );
}

const int MAX = 100010;
int N;
ponto in[MAX], n[MAX][2];

ponto midpoint(ponto a, ponto b){
	ponto ret;
	ret.x=(a.x+b.x)/2.0, 
	ret.y=(a.y+b.y)/2.0;
	return ret;
}

double area(int base, int i, int l1, int l2){
	vec a, b;
	a=ponto(n[0][base], n[i][l1]);
	b=ponto(n[0][base], n[i-1][l2]);
	return fabs(a%b)/2.0; 
}
double pd[MAX][2][2][2][2][2];

double solve(int i, int l, int p, int ini, int dic, int seg){
	
	int aux;
	if(i==N){
		aux=ccw(n[i-2][l], n[i-1][p], n[0][ini]);
		if(aux!=dic) return INF;
		
		aux=ccw(n[i-1][p], n[0][ini], n[1][seg]);
		if(aux!=dic) return INF;
		
		return 0.0;
	}
		
	aux=1; if(dic==-1) aux=0;
	double &pp=pd[i][l][p][ini][aux][seg];
	if(pp>-INF+EPS) return pp;

	double ret=0.0, aa=INF, bb=INF; 
	
	if(i==0){
		aa=solve(i+1, p, 0, 0, dic, seg);
		bb=solve(i+1, p, 1, 1, dic, seg);
	}else if(i==1){
		aa=solve(i+1, p, 0, ini, dic, 0);
		bb=solve(i+1, p, 1, ini, dic, 1);
	}else{
		aux=ccw(n[i-2][l], n[i-1][p], n[i][0]);
		if(aux == dic || aux==0)
			aa=solve(i+1, p, 0, ini, dic, seg) + area(ini, i, 0, p);
			
		aux=ccw(n[i-2][l], n[i-1][p], n[i][1]);
		if(aux == dic || aux==0)
			bb=solve(i+1, p, 1, ini, dic, seg) + area(ini, i, 1, p);
	}
	
	ret=min(aa, bb);
	
	return pp=ret;
}

int main(){
	
	scanf("%d", &N);
	rep(i, 0, N+2) scanf("%lf %lf", &in[i].x, &in[i].y);
	
	rep(i, 0, N+1){
		rep(j, 0, 2)
		rep(k, 0, 2)
		rep(l, 0, 2) 
		rep(m, 0, 2) 
		rep(n, 0, 2) pd[i][j][k][l][m][n]=-INF;
		if(i==N) continue;
		n[i][0]=midpoint(in[i], in[N]);
		n[i][1]=midpoint(in[i], in[N+1]);	
	}	n[N][0]=n[0][0], n[N][1]=n[0][1]; 
	
	double a=solve(0, 0, 0, 0, 1, 0),
			 b=solve(0, 0, 0, 0, -1, 0);
	double out=min(a, b);
				
	printf("%.3lf\n", out);
}
