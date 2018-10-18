// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Qual é a Altura?
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2864

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main(){
	
	int T; cin >> T;
	while(T--){
	    double a, b, c; cin >> a >> b >> c;
	    //ax² + bx + c
	    //2ax + b = 0
	    //x = -b/2a
	    double x = -b/(2.0*a);
	    double ans = a*x*x + b*x + c;
	    cout << fixed << setprecision(2) << ans << '\n';
	}
	

	return 0;
} 
