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
	double abs() { return sqrt(x*x+y*y); }
	void read() { cin >> x >> y; }
	void debug() { cout << "x: " << x << " y: " << y << '\n'; }
	double operator *(ponto q){ return x*q.x + y*q.y; }
	double operator %(ponto q){ return x*q.y - y*q.x; }
};

int main(){
	
	ponto p1, p2, p;
	p1.read(), p2.read();
	
	int n; cin >> n;
	int qo = 0, qho = 0, ql = 0, qhl = 0, ca = 0, aux;
	
	printf("Relatorio Vogon #35987-2\n");
	printf("Distancia entre referencias: %.2lf anos-luz\n", ponto(p1, p2).abs());
	rep(i, 0, n){
		p.read(); cin >> aux;
		int cross = ponto(p1, p2)%ponto(p1, p);
		if(cross == 0) ca++;
		else if(cross > 0) qo++, qho+=aux;
		else if(cross < 0) ql++, qhl+=aux;
	}
	
	printf("Setor Oeste:\n");
	printf("- %d planeta(s)\n", qo);
	printf("- %d bilhao(oes) de habitante(s)\n", qho);
	printf("Setor Leste:\n");
	printf("- %d planeta(s)\n", ql);
	printf("- %d bilhao(oes) de habitante(s)\n", qhl);
	printf("Casualidades: %d planeta(s)\n", ca);
		
	return 0;
} 
