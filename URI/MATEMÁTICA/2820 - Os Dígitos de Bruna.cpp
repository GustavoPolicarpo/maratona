// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Os Dígitos de Bruna
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2820

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
		
		int D; cin >> D;
		int V[D]; rep(i, 0, D) cin >> V[i]; sort(V, V+D);
		ll N; cin >> N; N--;
		string C;
		
		ll t = 1, aux = 1;
		while(42){
			if(N>=aux*D){
				N-=aux*D;
				aux = aux*D;
				t++;
			}else{
				break;
			}
		}
		
		while(N){
			C.pb(N%D+'0');
			N/=D;
		}
		while(C.size()<t) C.pb('0');
		reverse(C.begin(), C.end());
		
		//cout << C << '\n';
		rep(i, 0, C.size()) cout << V[C[i]-'0']; cout << '\n';
		
	}
	
	return 0;
} 
