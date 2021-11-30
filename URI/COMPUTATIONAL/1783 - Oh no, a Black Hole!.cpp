// Author: Gustavo Policarpo
// Name: Oh no, a Black Hole!
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1783

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

struct ponto{
	double x, y;
};

int main()
{
	int T, z=1; cin >> T;
	while(T--){
		ponto a1, b1, a2, b2;
		scanf("%lf %lf %lf %lf", &a1.x, &a1.y, &b1.x, &b1.y);
		scanf("%lf %lf %lf %lf", &a2.x, &a2.y, &b2.x, &b2.y);
		
		ponto da, db;
		da.x=(a2.y-a1.y), da.y=-(a2.x-a1.x);
		db.x=(b2.y-b1.y), db.y=-(b2.x-b1.x);
		
		ponto a, b;
		a.x=(a1.x+a2.x)/2.0, a.y=(a1.y+a2.y)/2.0,
		b.x=(b1.x+b2.x)/2.0, b.y=(b1.y+b2.y)/2.0;
		
		double t;
		if(da.x!=0)
			t=(a.y+(b.x-a.x)/da.x*da.y-b.y)/(db.y-db.x/da.x*da.y);
		else
			t=(a.x-b.x)/db.x;
		
		ponto out;
		out.x=b.x+t*db.x, out.y=b.y+t*db.y;
		
		printf("Caso #%d: %.2lf %.2lf\n", z++, out.x, out.y);		
	}
		
return 0;
}
