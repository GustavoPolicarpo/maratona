// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pirâmide
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2873

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
	
	//c - d
	//x - b+a/2
	//x = ((b+a/2)*c)/d;
	double a, b, c, d;
	while(cin >> a >> b >> c >> d){
		if(a<1) break;
		double x = ((b+a/2.0)*c)/d;
		cout << fixed << setprecision(5) << x << '\n';
	}

	
	return 0;
} 
