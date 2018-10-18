// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Prelúdio de um Casamento ...
// Nível: 5
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1857

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


int Area_Poligono(poligono T){ 
	int ans=0.0; 
	T.pb(T[0]); 
	rep (i, 0, T.size()-1) 
		ans += (T[i] % T[i+1]); 
	return fabs(ans); 
}

ponto n[120];
int N, B;


bool mysort(ponto a, ponto b){
	int aux=ccw(n[0], a, b);
	if(aux!=1) return false;
	return true;
}

int pd[111][111];

int myarea(int a, int b, int c){
	poligono go;
	go.pb(n[a]);
	go.pb(n[b]);
	go.pb(n[c]);
	return Area_Poligono(go);
}

int solve(int i, int last){
	
	if(i==N+1) return 0;
	if(pd[i][last]!=-1) return pd[i][last];
	
	int ret=0;
	
	if(last==0)
	rep(j, i+1, N+1){
		int aux=solve(j, i)+myarea(0, i, j);
		if(aux<=2*B) ret=max(ret, aux);
	}
	
	else
	rep(j, i+1, N+1){
		if(ccw(n[last], n[i], n[j])==1){
			int aux=solve(j, i)+myarea(0, i, j);
			if(aux<=2*B) ret=max(ret, aux);
		}
	}
	
	return pd[i][last]=ret;
	
}

int main(){
	
	scanf("%d %d", &N, &B);
	
	rep(i, 0, N+2) rep(j, 0, N+2) pd[i][j]=-1;
		
	rep(i, 0, N+1) cin >> n[i].x >> n[i].y;
	
	sort(n+1, n+N+1, mysort);
	
	//cout << '\n';
	//rep(i, 0, N+1) cout << n[i].x << " " << n[i].y << '\n';
	
	int ans=0;
	rep(i, 1, N){
		ans=max(ans, solve(i, 0));
	}
	
	cout << double(ans)/2.0 << '\n';
	
	return 0;
	
}
