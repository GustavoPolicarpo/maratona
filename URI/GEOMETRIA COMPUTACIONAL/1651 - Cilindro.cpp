// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cilindro
// Nível: 6
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1651

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;
typedef pair <int, int> ii;
typedef long long int ll;

#define PI acos(-1.0)

int main(){
	
	int w, h;
	while(cin >> w >> h){
		if(!w && !h) break;
		double ans = 0.0;
		double r1 = min(h/3.0, w/(2.0*PI));
		double r2 = min(h/(2.0 + 2.0*PI), w/(2.0));
		double v1 = r1*r1*PI*(h-2.0*r1);
		double v2 = r2*r2*PI*w;
		printf("%.3lf\n", max(v1, v2));
	}

	return 0;
}
