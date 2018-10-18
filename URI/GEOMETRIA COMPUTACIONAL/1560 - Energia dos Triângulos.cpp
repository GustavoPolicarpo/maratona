// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Energia dos Triângulos
// Nível: 5
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1560

#define gc getchar_unlocked
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

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007 

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

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


const double EPS = 1e-9;



inline int cmp( double x, double y = 0, double tol = EPS) 
{ 
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); 
}

struct ponto
{
	int x, y;
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

int main()
{
	int N, M;
	while(scanf("%d %d", &N, &M) !=EOF){
		ponto preto[N], branco[M];
		int x, y;
		rep(i, 0, N)
			scanint(preto[i].x), scanint(preto[i].y);
		rep(i, 0, M)
			scanint(branco[i].x), scanint(branco[i].y);
			
		sort(preto, preto+N);
		sort(branco, branco+M);
		
		int xmin, xmax, ymin, ymax, aux, g1, g2; ll out=0;
		rep(i, 0, N){
			xmin=preto[i].x;
			rep(j, i+1, N){
				rep(k, j+1, N){
					xmax=preto[k].x, aux=0;
					rep(l, 0, M){
						if(branco[l].x<=xmin) continue;
						if(branco[l].x>=xmax) break;
						g1=ccw(preto[i],preto[j],branco[l]), 
						g2=ccw(preto[j],preto[k],branco[l]);
						if(g1==g2 && g2==ccw(preto[k],preto[i],branco[l]))
							aux++; 							
					}
					out+=aux*aux;
				}
			}
		}
		cout << out << "\n";
	}
		
return 0;
}
