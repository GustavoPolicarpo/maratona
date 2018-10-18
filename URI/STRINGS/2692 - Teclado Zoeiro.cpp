// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Teclado Zoeiro
// Nível: 1
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2692

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define pb push_back
#define F first
#define S second

using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;



int main(){
	
	char let[266]; rep(i, 0, 266) let[i] = i;
	int n, m; string s;
	
	getline(cin, s);
	
	int p = 0, v[10]; v[0] = v[1] = 0;
	rep(i, 0, s.size()){
		if(isdigit(s[i])){
			v[p]*=10;
			v[p]+=s[i]-'0';
		}else{
			p++;
		}
	}
	
	n = v[0], m = v[1];
	
	char a, b;
	
	while(n--){
		getline(cin, s);
		a = s[0], b = s[2];
		let[a] = b;
		let[b] = a;
	}
	
	while(m--){
		getline(cin, s);
		rep(i, 0, s.size()) cout << let[s[i]]; cout << '\n';
	}
		
	return 0;
}
