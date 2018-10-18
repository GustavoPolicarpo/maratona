// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ingrest
// Nível: 4
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2541

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


double Area_Poligono(poligono T){ 
	double ans=0.0; 
	T.pb(T[0]); 
	rep (i, 0, T.size()-1) 
		ans += (T[i] % T[i+1]); 
	return fabs(ans)/2.0; 
}


ponto pivot;


bool radial_lt(ponto a, ponto b)
{
	int R = ccw(pivot, a, b);
	if(R==0) return (pivot-a)*(pivot-a) <
					(pivot-b)*(pivot-b);
	else return (R==1);
}

poligono GrahamScan(vector <ponto> T){
	
	sort(ALL(T));
	T.resize(unique(ALL(T))-T.begin());
	
	int j=0, k, n=T.size();
	poligono U; 
	pivot=T[0];
	
	sort(++T.begin(), T.end(), radial_lt);
	
	for(k=n-2; k>=0 && ccw(T[0],T[n-1],T[k])==0; k--);
	reverse((k+1)+ALL(T));
	
	ponto aux;
	rep(i, 0, n){
		while(j>1 && ccw(U[j-2], U[j-1], T[i]) < 0){
			U.pop_back(), j--;
		}
				
		U.pb(T[i]); j++;
	}
	return U;
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int n;
	while(scanf("%d", &n)!=EOF){
		vector <ponto> v; ponto aux;
		rep(i, 0, n){
			scanf("%lf %lf", &aux.x, &aux.y);
			v.pb(aux);
		}
		
		printf("%.2lf\n", Area_Poligono(GrahamScan(v)));
		
	}
	
	
	return 0;
	
}
