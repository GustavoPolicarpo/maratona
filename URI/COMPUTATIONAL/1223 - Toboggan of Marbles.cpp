// Author: Gustavo Policarpo
// Name: Toboggan of Marbles
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1223

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

typedef pair < ponto, ponto > ii;
	
double PTSeg1(ponto p, ponto r, ponto s) 
{
    ponto A = p - s, B = p - r, C = s - r;
    double a = A * A, b = B * B, c = C * C;
    if (cmp(b, a + c) >= 0 ) return sqrt(a);
    else if (cmp(a, b + c) >= 0 ) return sqrt(b);
    else return fabs(A % B ) / sqrt(c);
}

int main()
{	
	int N;
	while(scanf("%d", &N) !=EOF){
		int L, H;
		scanf("%d %d", &L, &H);
		vector <ii> l;
		double md=INF, aux;
		ponto a, b;
		int yf, xf, yi;
		rep(i, 1, N+1){
			scanf("%d %d %d", &yi, &xf, &yf);
			if(i%2==1){
				aux=L-xf;
				if(aux<md) md=aux;
				a.x=0.0, a.y=yi, b.x=xf, b.y=yf;
			}
			else{
				aux=xf;
				if(aux<md) md=aux;
				a.x=L, a.y=yi, b.x=xf, b.y=yf;				
			}
			l.pb(mp(a, b));
		}
		rep(i, 0, N-1){
			aux=PTSeg1(l[i].S, l[i+1].F, l[i+1].S);
			if(aux<md) md=aux;	
		}
		printf("%.2lf\n", md);
	}	
	
return 0;
}
