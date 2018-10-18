// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Preparando a Produção
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2775

#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)

using namespace std;


int main(void) {
	int n;
	int v[1005], p[1005];
	
	while(cin >> n) {
		rep(i, 0, n) cin >> v[i];
		rep(i, 0, n) cin >> p[i];
		
		int ans = 0, ordenado = 0;
		while(!ordenado){
			ordenado = 1;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n-1; j++) {
					if(v[j+1] < v[j]) {
						swap(v[j+1], v[j]);
						swap(p[j+1], p[j]);
						ans += p[j+1] + p[j];
						ordenado = 0;
					}
				}
			}
		}
		
		
		cout << ans << endl;
	}   	
	return 0;
}

