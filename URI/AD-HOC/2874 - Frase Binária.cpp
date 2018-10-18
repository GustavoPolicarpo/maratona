// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Frase Binária
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2874

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
		string s;
		rep(i, 0, T){
			cin >> s;
			int n = 0;
			rep(i, 0, s.size()){
				n*=2;
				n+=s[i]-'0';
			}
			cout << (char)(n);
		}
		cout << '\n';
		
	}

	return 0;
} 
