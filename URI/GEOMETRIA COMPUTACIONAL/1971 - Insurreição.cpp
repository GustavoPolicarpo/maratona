// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Insurreição
// Nível: 4
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1971

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

ponto pivot;
bool radial_lt(ponto a, ponto b){
    int r=ccw(pivot, a, b);
    if(r==0) return (pivot-a)*(pivot-a)<(pivot-b)*(pivot-b);
    else return r==1;
}

#define point ponto
double angle(point a, point b, point c){ 
	vec u = vec(a,b), v = vec(a,c); 
	return atan2((u%v),(u*v));
}

int inPolygon(point p, vector<point>P){
	if ((int)P.size() == 0) return false; 
	double sum = 0; P.pb(P[0]);
	rep(i,0,P.size()-1){ // assume that the first vertex 
		if (entre(P[i], p, P[i+1])) return 0;
		if (ccw(p, P[i], P[i + 1]) == -1) sum -= angle(p, P[i], P[i + 1]);
		else sum += angle(p, P[i], P[i + 1]); 
	}
	
	if (fabs(sum - 2.0*M_PI) < EPS || fabs(sum + 2.0*M_PI) < EPS) return 1; 
	return -1; 
}

void print(int ans){
	if(ans!=-1){
		printf("\\O/\n");
		printf(" | \n");
		printf("/ \\\n");
	}else{
		printf(" O>\n");
		printf("<| \n");
		printf("/ >\n");
	}
}
int main()
{
	
	vector <ponto> v; ponto aux;
	
	rep(i, 0, 4){
		cin >> aux.x >> aux.y;
		v.pb(aux);
	}
	
	cin >> aux.x >> aux.y;
	
	sort(v.begin(), v.end()); pivot=v[0];
	sort(++v.begin(), v.end(), radial_lt); 

	int cnt=0;
	if(entre(v[0], v[1], v[3])) cnt++;
	if(entre(v[0], v[2], v[3])) cnt++;
	if(cnt==2){
		print( -1 );
		return 0;
	}
	
	print( inPolygon(aux, v) );
	
	return 0;
	
}
