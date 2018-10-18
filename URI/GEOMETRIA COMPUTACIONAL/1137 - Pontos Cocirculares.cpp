// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pontos Cocirculares
// Nível: 6
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1137

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

const double EPS = 1e-5;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, ii > iii;


struct ponto{
	double x, y;
};
struct circ{
	double a, b, c, bum;
};

circ defcirc(ponto a, ponto b, ponto c)
{
	circ ret;
	double l1=-(a.x*a.x+a.y*a.y), l2=-(b.x*b.x+b.y*b.y), l3=-(c.x*c.x+c.y*c.y);  
	double den=
	(a.x*b.y + a.y*c.x + b.x*c.y) - (b.y*c.x + a.y*b.x + a.x*c.y);
	//cout << den << endl;
	if(den==0){
		ret.bum=1; return ret;
	}
	else ret.bum=0;
	ret.a=((l1*b.y + a.y*l3 + l2*c.y) - (b.y*l3 + a.y*l2 + l1*c.y))/den;
	ret.b=((a.x*l2 + l1*c.x + b.x*l3) - (l2*c.x + l1*b.x + a.x*l3))/den;
	ret.c=((a.x*b.y*l3 + a.y*c.x*l2 + b.x*c.y*l1) - (b.y*c.x*l1 + a.y*b.x*l3 + a.x*c.y*l2))/den;
	return ret;
}

int main()
{
	int N;
	while(scanf("%d", &N) && N){
		ponto n[N], centro;
		rep(i, 0, N)
			scanf("%lf %lf", &n[i].x, &n[i].y);	
		int out, temp;
		circ usa;
		double aux;
		if(N==1) out=1;
		else out=2;
		rep(i, 0, N){
			rep(j, i+1, N){
				rep(k, j+1, N){
					usa=defcirc(n[i], n[j], n[k]); 
					if(usa.bum) continue; temp=3;
					rep(l, 0, N){
						if(i==l || j==l || k==l) continue;
						aux=n[l].x*n[l].x+n[l].y*n[l].y+
						n[l].x*usa.a+n[l].y*usa.b+usa.c;
						if(fabs(aux)<EPS) temp++;		
					}
					if(temp>out) out=temp;
				}
			}
		}
		cout << out << endl;	
	}
		
return 0;
}
