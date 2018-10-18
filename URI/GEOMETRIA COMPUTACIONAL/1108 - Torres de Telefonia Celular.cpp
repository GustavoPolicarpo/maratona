// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Torres de Telefonia Celular
// Nível: 7
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1108

#include <bits/stdc++.h>

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

typedef long long int ll;
typedef pair < int, int > ii;

const ll LINF = 1LL << 60;

struct pontO{
	double x, y;
};

struct circ{
	double r;
	pontO centro; 
};

circ defcirc(pontO a, pontO b, pontO c){
	
	double x1 = a.x, x2 = b.x, x3 = c.x;
    double y1 = a.y, y2 = b.y, y3 = c.y;

    double mr = (y2-y1) / (x2-x1);
    double mt = (y3-y2) / (x3-x2);
	
	circ ret;
	
    if (mr == mt) {
    	ret.r=-1;
        return ret;
    }

    ret.centro.x = (mr*mt*(y3-y1) + mr*(x2+x3) - mt*(x1+x2)) / (2*(mr-mt));
    ret.centro.y = (y1+y2)/2 - (ret.centro.x - (x1+x2)/2) / mr;
	ret.r = pow((pow((x2-ret.centro.x), 2) +  pow((y2-ret.centro.y), 2)), 0.5);
	
	/*ponto a, b, c;
	cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
	circ out=defcirc(a, b, c);
	cout << out.centro.x << " " << out.centro.y << " " << out.r << '\n';*/
    
    return ret;
	
}

const double EPS = 1e-9;

inline int cmp( double x, double y = 0, double tol = EPS) 
{ 
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); 
}

struct ponto{
	
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

double norma(vec u) 
{
	return sqrt(u*u); 
}

typedef pair<ponto, double> circulo; 
bool in_circle(circulo C, ponto p) 
{ 
	return cmp( norma(p-C.first), C.second) <= 0; 
}

ponto circumcenter(ponto p, ponto q, ponto r) 
{ 
	ponto a = p-r, b = q-r, c = ponto(a*(p+r)/2, b*(q+r)/2); 
	return ponto(c % ponto(a.y, b.y), ponto(a.x, b.x)%c) / (a%b); 
}

double dst(ponto a, ponto b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

circulo spanning_circle(vector<ponto>& T) 
{ 
	int n = T.size(); 
	circulo C(ponto(), 0.0);
	
	if(n<=1) return C;
	if(n==2){
		C.S=dst(T[0], T[1])/2.0;
		return C;
	}
	
	random_shuffle(ALL(T)); 
	
	for (int i = 0; i < n; i++) 
		if (!in_circle(C, T[i])){ 
			C = circulo(T[i], 0);
			for (int j = 0; j < i; j++) 
				if (!in_circle(C, T[j])){
					C = circulo((T[i] + T[j]) / 2, norma(T[i] - T[j]) / 2);
					for (int k = 0; k < j; k++) 
						if (!in_circle(C, T[k])){
							ponto o = circumcenter(T[i], T[j], T[k]); 
							C = circulo(o, norma(o - T[k]));
						}
				}
		}
	return C;
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N;
	
	while(scanf("%d", &N) and N){
		
		ponto in[N];
		
		rep(i, 0, N) cin >> in[i].x >> in[i].y;
		
		double ans=LINF;
		
		cout << fixed << setprecision(2);
		
		if(N==3){
			ans=min(dst(in[0], in[1]), min(dst(in[0], in[2]), dst(in[1], in[2])));
			ans/=2.0;
		}
		
		if(N==4){
			ans=max(dst(in[0], in[1]), dst(in[2], in[3]));
			ans=min(ans, max(dst(in[0], in[2]), dst(in[1], in[3])));
			ans=min(ans, max(dst(in[0], in[3]), dst(in[1], in[2])));
			ans/=2.0;
		}
		
		
		rep(a, 0, N){
			rep(b, a+1, N){
				rep(c, b+1, N){
					vector <ponto> TT; TT.pb(in[a]), TT.pb(in[b]), TT.pb(in[c]);
					circulo atual=spanning_circle(TT); TT.clear();
					rep(d, 0, N){
						if(dst(in[d], atual.F) > atual.S+EPS){
							TT.pb(in[d]);
						}
					}
					ans=min(ans, max(atual.S, spanning_circle(TT).S));
				}
			}
		}
		
		cout << ans << '\n';
		
	}
	
	return 0;
	
}
