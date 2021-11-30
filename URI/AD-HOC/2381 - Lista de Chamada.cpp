// Author: Gustavo Policarpo
// Name: Lista de Chamada
// Level: 1
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2381

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
