// Author: Gustavo Policarpo
// Name: Hit the Target!
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1899

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

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;


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


const double EPS = 1e-9;

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

typedef pair < ponto, ponto > ii;

int main()
{
	int N; cin >> N;
	ii in[N+1]; ponto bola; bola.x=0.0, bola.y=0.0;
	double d;
	rep(i, 0, N+1){
		scanf("%lf %lf %lf", &d, &in[i].F.y, &in[i].S.y);
		in[i].F.y-=0.000001, in[i].S.y+=0.000001;
		in[i].F.x = in[i].S.x=d;
	}
	
	int topo=N, base=N;
	
	bool yep=true;
	for(int i=N-1; i>=0; i--){
		ponto chao; chao.x=in[i].F.x, chao.y=0.0;
		ponto teto; teto.x=in[i].S.x, teto.y=1000000.0;
		
		if(intersect_seg(in[base].F, bola, in[i].S, teto)){
			yep=false;
			break;
		}
		if(intersect_seg(in[topo].S, bola, in[i].F, chao)){
			yep=false;
			break;
		}
		
		if(intersect_seg(in[base].F, bola, in[i].F, chao)){
			base=i;
		} 
		if(intersect_seg(in[topo].S, bola, in[i].S, teto)){
			topo=i;	
		} 
	}
	
	if(yep) puts("Y");
	else puts("N");


return 0;
}
