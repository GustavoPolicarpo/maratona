// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Fantástico Bolo de Bobby
// Nível: 3
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1631

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

double norma(vec u) 
{
	return sqrt(u*u); 
}
	
int ccw(ponto p, ponto q, ponto r)
{
	return cmp( vec(p,q) % vec(p,r) );
}
vec projecao(vec a, vec b)
{
	return b * ((a*b) / (b*b));
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

double PTSeg1(ponto p, ponto r, ponto s) 
{
    ponto A = p - s, B = p - r, C = s - r;
    double a = A * A, b = B * B, c = C * C;
    if (cmp(b, a + c) >= 0 ) return sqrt(a);
    else if (cmp(a, b + c) >= 0 ) return sqrt(b);
    else return fabs(A % B ) / sqrt(c);
}

double PTReta(ponto p, ponto a, ponto b) 
{ 
	ponto pp = a + projecao(vec(a,p), vec(a,b)); 
	return norma(p-pp); 
}

int main()
{
	int N;
	while(scanf("%d", &N) and N){
		ponto n[N];
		rep(i, 0, N)
			scanf("%lf %lf", &n[i].x, &n[i].y);
		double out=INF, se=0, sd=0, aux;
		rep(i, 0, N){
			rep(j, i+1, N){
				se=0.0, sd=0.0;
				rep(k, 0, N){
					if(i==k || j==k) continue;
					if(ccw(n[i],n[k],n[j])==1){
						aux=PTReta(n[k],n[i],n[j]);
						sd+=fabs(aux);
					}
					else if(ccw(n[i],n[k],n[j])==-1){
						aux=PTReta(n[k],n[i],n[j]);
						se+=fabs(aux);
					}
				}
				if(fabs(sd-se)<out) out=fabs(sd-se);
			}
		}
		printf("%.3lf\n", out);
		
	}
	
return 0;
}
