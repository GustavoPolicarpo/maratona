// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Protocolo TCP/IP
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2872

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
	
	int T;
	while(cin >> T){
		vector <string> vs; string a, b;
		while(cin >> a){
			if(a=="0") break;
			cin >> b; vs.pb(b);
		}
		
		sort(vs.begin(), vs.end());
		rep(i, 0, vs.size()) cout << "Package " << vs[i] << '\n';
		cout << '\n';
	}

	return 0;
} 
