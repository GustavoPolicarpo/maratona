// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Complexo, Difícil e Compl...
// Nível: 4
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1465

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	
	int T; cin >> T;
	
	double maximun=powl(2LL,30);
	
	while(T--){
		
		long double A, B; cin >> A >> B;
		complex <long double> n(A,B), base(A, B);
		
		int ans=1;
		
		while(1){
			
			if(n.imag()==0) break;
			if(abs(n)>maximun){
				ans=-1;
				break;
			}
			
			n=n*base,ans++;
			
		}
		
		if(ans==-1) puts("TOO COMPLICATED");
		else cout << ans << '\n';
		
	}
		
	return 0;
	
}
