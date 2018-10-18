// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Lista de Chamada
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2381

#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n, m; 
	cin >> n >> m;
	vector <string> in; string aux;
	while(n--){
		cin >> aux;
		in.push_back(aux);
	}
	
	sort(in.begin(), in.end());
	
	cout << in[m-1] << '\n';
	
	return 0;
	
}
