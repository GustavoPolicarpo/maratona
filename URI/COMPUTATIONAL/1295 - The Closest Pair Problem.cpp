// Author: Gustavo Policarpo
// Name: The Closest Pair Problem
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1295

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

double dPT(ponto a, ponto b)
{
	return ((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
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

ponto pivot;

bool radial_lt(ponto a, ponto b)
{
	int R = ccw(pivot, a, b);
	if(R==0) return (pivot-a)*(pivot-a) <
					(pivot-b)*(pivot-b);
	else return (R==1);
}

//set <ponto>
poligono GrahamScan(vector <ponto> T){
	
	sort(ALL(T));
	T.resize(unique(ALL(T))-T.begin());
	
	int j=0, k, n=T.size();
	poligono U; //set <ponto> u; stack <ponto> w;
	int P0=0;
	pivot=T[P0];
	swap(T[0], T[P0]);
	
	sort(++T.begin(), T.end(), radial_lt);
	
	for(k=n-2; k>=0 && ccw(T[0],T[n-1],T[k])==0; k--);
	reverse((k+1)+ALL(T));
	
	ponto aux;
	rep(i, 0, n){
		while(j>1 && ccw(U[j-2], U[j-1], T[i]) < 0){
			U.pop_back(), j--;
			/*if(u.count(w.top()))
				u.erase(w.top()), w.pop();*/
		}
				
		U.pb(T[i]); j++;
		//u.insert(T[i]); w.push(T[i]);	
		
	}
	return U;
}


bool comp(ponto a, ponto b)
{
	return a.disO<b.disO;
}

int main()
{
	//freopen("out.txt", "w", stdout);
	int N;
	while(cin >> N && N){
		vector <ponto> T;
		ponto aux; double x, y;
		ponto ori; ori.x=0, ori.y=0;
			
		rep(i, 0, N){
			scanf("%lf %lf", &x, &y);
			aux.x=x, aux.y=y;
			aux.disO=dPT(aux, ori);
			T.pb(aux);
			
		}
		
		double menor_dist=INF, d;
		
		sort(T.begin(), T.end(), comp);
		rep(i, 0, N-1){
			d=dPT(T[i], T[i+1]);			
			if(d<menor_dist)
				menor_dist=d;
		}
		
		sort(T.begin(), T.end());
		rep(i, 0, N-1){
			d=dPT(T[i], T[i+1]);			
			if(d<menor_dist)
				menor_dist=d;
		}
		
		menor_dist=sqrt(menor_dist);
		if(menor_dist<10000)
			printf("%.4lf\n", menor_dist);
		else
			printf("INFINITY\n");
					
	}
	
return 0;
}
