// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Final do ICPC
// Nível: 7
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1455

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

inline double getDouble(FILE *f = stdin) {
    char ch;
    bool seen = false;
    bool sign = false;
    char values[10];
    double result =0.;
    bool beforeDot = true;
    int beforeLength = 0;
    double multiplier;

    while((ch = getc(stdin)) != EOF) {
        if(ch == '-') {
            sign = true;
            continue;
        }
        if(ch == ' ' || ch == '\n') {
            if(seen) break;
            continue;
        }
        if(ch == '.') {
            beforeDot = false;
            multiplier = 1.;
            while(beforeLength) {
                result += (double)(values[--beforeLength] - '0') * multiplier;
                multiplier *= 10.;
            }
            multiplier = 10.;
        }
        else {
            if(!beforeDot)
            {
                result += double(ch - '0') / multiplier;
                multiplier *= 10.;
            } else {
                values[beforeLength++] = ch;
            }
            seen = true;
        }
    }
    if(beforeDot) {
        multiplier = 1;
        while(beforeLength) {
            result += (double)(values[--beforeLength] - '0') * multiplier;
            multiplier *= 10.;
        }
    }

    if(sign) result *= -1.;

    return result;
}

circulo spanning_circle(vector<ponto>& T) 
{ 
	int n = T.size(); 
	random_shuffle(ALL(T)); 
	circulo C(ponto(), 0.0);
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
	int n, z=1;
	while(scanf("%d", &n) && n){
		vector <ponto> t;
		ponto aux;
		rep(i, 0, n){
			scanf("%lf %lf", &aux.x, &aux.y);
			t.pb(aux);
		}
		circulo out = spanning_circle(t); aux=out.F;
		printf("Instancia %d\n", z++);
		printf("%.2lf %.2lf %.2lf\n\n", aux.x, aux.y, out.S);
	}
		
return 0;
}
