// Author: Gustavo Policarpo
// Name: Vogons!
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1834

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

//rotação de p->q->r 
int ccw(ponto p, ponto q, ponto r)
{
	return cmp( vec(p,q) % vec(p,r) );
}

double dPT(ponto a, ponto b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
	int N, n, o=0, no=0, e=0, ne=0, c=0;
	ponto p1, p2, p;
	
	scanf("%lf %lf %lf %lf", &p1.x, &p1.y, &p2.x, &p2.y);
	double dist=dPT(p1,p2);
	
	scanf("%d", &N);
	rep(i, 0, N){
		scanf("%lf %lf %d", &p.x, &p.y, &n);
		int aux=ccw(p1,p2,p);
		if(aux==1) o++, no+=n;
		else if(aux==-1) e++, ne+=n;
		else c++;	
	}
	
	printf("Relatorio Vogon #35987-2\n");
	printf("Distancia entre referencias: %.2lf anos-luz\n", dist);
	printf("Setor Oeste:\n");
	printf("- %d planeta(s)\n- %d bilhao(oes) de habitante(s)\n", o, no);
	printf("Setor Leste:\n");
	printf("- %d planeta(s)\n- %d bilhao(oes) de habitante(s)\n", e, ne);
	printf("Casualidades: %d planeta(s)\n", c);
		
return 0;
}
