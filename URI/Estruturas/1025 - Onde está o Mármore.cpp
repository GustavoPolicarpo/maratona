// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Onde está o Mármore?
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1025

#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<b; i++)

int main(){
	
	int N, K, teste=1;
	
	while(scanf("%d %d", &N, &K) and N+K){
		
		printf("CASE# %d:\n", teste++);
		
		int v[N]; rep(i, 0, N) scanf("%d", &v[i]);
		
		sort(v, v+N);
		
		int num;
		while(K--){
			scanf("%d", &num); int found=-1;
			rep(i, 0, N){
				if(v[i]==num){
					found=i+1;
					break;
				}
			}
			
			if(found!=-1) printf("%d found at %d\n", num, found);
			else printf("%d not found\n", num);
			
		}
		
	}
	
	return 0;
	
}
