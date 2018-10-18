// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Diamantes e Areia
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1069

#include <bits/stdc++.h>

#define pb push_back 
#define mp make_pair 
#define F first 
#define S second 
#define rep(i, a, b) for(int i=a; i<b; i++)

using namespace std;

typedef pair <double, string> ii;
typedef long long int ll;


int main(){
	
		
	int n; cin >> n;
	string s;
	
	while(n--){
		
		cin >> s;
		int cnt=0;
		
		stack <char> st;
		
		rep(i, 0, s.size()){
			if(s[i]=='<') st.push('<');
			else if(s[i]=='.' || !st.size()) continue;
			else st.pop(), cnt++;
		}
		
		cout << cnt << '\n';
		
	}
	
	return 0;
	

}

