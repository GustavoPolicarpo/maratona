// Author: Gustavo Policarpo
// Name: Confederation
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1710

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
	double x, y, z, disO;
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

struct plano
{
	double x, y, z, d;
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


int main()
{
	//freopen("in.txt", "r", stdin);
	
	int N, M; cin >> N >> M;
	
	plano n[N];
	ponto p[M];
	
	double x, y, z, d;
	
	rep(i, 0, N){
		scanf("%lf %lf %lf %lf", &x, &y, &z, &d);
		n[i].x=x, n[i].y=y, n[i].z=z, n[i].d=d;
	}
	
	rep(i, 0, M){
		scanf("%lf %lf %lf", &x, &y, &z);
		p[i].x=x, p[i].y=y, p[i].z=z;
	}
	
	map <vector <int> , int > ans; int out=0;
	
	rep(i, 0, M){
		vector <int> v;
		rep(j, 0, N){
			int aux=p[i].x*n[j].x + p[i].y*n[j].y + p[i].z*n[j].z;
			if(aux>n[j].d) aux=1;
			else aux=-1;
			v.pb(aux);
		}
		ans[v]++;
		out=max(out, ans[v]);
	}
	
	printf("%d\n", out);
	
	
	return 0;
	
}
