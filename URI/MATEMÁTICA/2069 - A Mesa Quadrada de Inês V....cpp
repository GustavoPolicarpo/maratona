// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Mesa Quadrada de Inês V...
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2069

#include <bits/stdc++.h>

using namespace std;

typedef long long int ll ;

int main() {

	ll A, B; cin >> A >> B;
	ll gc = __gcd(A, B), fim = sqrt(gc), ans = gc;
	vector <ll> v(fim+2, 0);
	
	for(int i=2; i<=fim; i++){
		while(gc%i==0){
			v[i]++;
			gc/=i;
		}
	}
	
	if(gc) ans*=gc;
	
	for(int i=2; i<=fim; i++){
		if(v[i]&1) ans*=i;
	}
	
	ll resp = sqrt(ans);
	cout << resp << '\n';
	
	return 0;
}
