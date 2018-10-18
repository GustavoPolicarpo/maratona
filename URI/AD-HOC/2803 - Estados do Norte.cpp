// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Estados do Norte
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2803

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
	
	set<string> st;
	st.insert("roraima");
	st.insert("acre");
	st.insert("amapa");
	st.insert("amazonas");
	st.insert("para");
	st.insert("rondonia");
	st.insert("tocantins");
	
	string s; cin >> s;
	if(st.count(s)) puts("Regiao Norte");
	else puts("Outra regiao");
	

	return 0;
}
