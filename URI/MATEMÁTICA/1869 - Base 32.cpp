// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Base 32
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1869

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;




int main(){
	
	ull N;
	while(cin >> N and N){
		string resp;
		while(N){
			if(N%32>=10) resp.pb((char)('A'+N%32-10));
			else resp.pb(N%32+'0');
			N/=32;
		}
		reverse(resp.begin(), resp.end());
		cout << resp << '\n';
	}
	
	puts("0");
	
	
	
	return 0;
} 
