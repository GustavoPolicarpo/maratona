// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Goemon em Apuros
// Nível: 4
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1613

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3f3f3f3f
#define MAXV 100001

typedef long long int ll;
typedef pair < double, double > ii;
typedef pair < double, int > iii;

const double EPS = 1e-9;

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
typedef vector<ponto> poligono;

ponto li(ponto p, ponto q, ponto r, ponto s){
    ponto a=q-p, b=s-r, c=ponto(p%q, r%s);
    if(a%b==0) return ponto(INF, INF);
    return ponto(ponto(a.x, b.x)%c, ponto(a.y, b.y)%c)/(a%b);
}

int main(){
	
	int T; cin >> T;
	
	while(T--){
		
		ponto E; scanf("%lf %lf", &E.x, &E.y);
		
		int P; scanf("%d", &P);
		
		vector <ii> wall; ii aux; ponto p;
		rep(i, 0, P){
			scanf("%lf %lf", &aux.S, &aux.F);
			wall.pb(aux);
		}
		
		sort(wall.begin(), wall.end());
		
		int G, ans=0; scanf("%d", &G);
		
		rep(i, 0, G){
			scanf("%lf %lf", &p.x, &p.y);
			p=li(E, p, ponto(0, 0), ponto(0, INF));
			
			int it=lower_bound(wall.begin(), wall.end(), ii(p.y, 0))-wall.begin();
			//cout << p.y << " " << it << '\n';
			
			if(it==wall.size()) continue;
			
			if(p.y > wall[it].S && p.y < wall[it].F) ans++;
		
		}
		
		cout << ans << '\n';
		
	}
	
	return 0;
	
}
