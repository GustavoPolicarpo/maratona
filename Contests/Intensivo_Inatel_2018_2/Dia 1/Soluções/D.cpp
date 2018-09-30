#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

#define EPS 1e-9

struct ponto{
	double x, y;
	ponto(){}
	ponto(double x, double y) :x(x), y(y) {}
	ponto (ponto a, ponto b) { x=(b.x-a.x); y=(b.y-a.y); }
	ponto operator +(ponto q){ return ponto(x+q.x, y+q.y); }
	ponto operator -(ponto q){ return ponto(x-q.x, y-q.y); }
	ponto operator /(double t){ return ponto(x/t, y/t); }
	void read() { cin >> x >> y; }
	void debug() { cout << "x: " << x << " y: " << y << '\n'; }
};

int main(){
	
	int T; cin >> T;
	
	rep(z, 1, T+1){
		ponto a1, a2, b1, b2;
		a1.read(), b1.read(), a2.read(), b2.read();
		
		ponto a = (a1+a2)/2, b = (b1+b2)/2;
		ponto aa = a2-a1, bb = b2-b1;
		ponto ap = ponto(-aa.y, aa.x), bp = ponto(-bb.y, bb.x);
		
		double ta; ponto out;
		if(fabs(bp.y)<=EPS) ta = (b.y-a.y)/(ap.y);
		else ta = (a.x-b.x-bp.x/bp.y*(a.y-b.y))/(bp.x*ap.y/bp.y - ap.x);
		
		out = ponto(a.x+ap.x*ta, a.y+ap.y*ta);
		printf("Caso #%d: %.2lf %.2lf\n", z, out.x+EPS, out.y+EPS);
		
	}
	
	return 0;
} 
