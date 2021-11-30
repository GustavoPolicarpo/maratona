// Author: Gustavo Policarpo
// Name: Inês Venezuela's Square T...
// Level: 7
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2069

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
