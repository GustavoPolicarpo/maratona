// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Escala de Cinza
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2630

#include <bits/stdc++.h>

#define INF 0x3f3f3f3f
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair

using namespace std;

typedef long long int ll;
typedef pair <long double, long double>  ii;

int main(){
	
	int T, z=1; cin >> T;
	
	while(T--){
		string s; cin >> s;
		int a, b, c; cin >> a >> b >> c;
		
		printf("Caso #%d: ", z++);
		if(s=="min") printf("%d\n", min(a, min(b, c)));
		else if(s=="max") printf("%d\n", max(a, max(b, c)));
		else if(s=="mean") printf("%d\n", (a+b+c)/3);
		else if(s=="eye") printf("%d\n", int(0.3*a + 0.59*b + 0.11*c));
	}
	
	
	
	return 0;
}
