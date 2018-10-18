// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Iu-Di-Oh!
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2542

#include <bits/stdc++.h>

#define pb push_back 
#define mp make_pair 
#define F first 
#define S second 
#define rep(i, a, b) for(int i=a; i<b; i++)

using namespace std;

typedef pair <int, int> ii;


int main(){
	
	int n;
	
	while(scanf("%d", &n)!=EOF){
		int m, l;
		scanf("%d %d", &m, &l);
		int ma[m][n], le[l][n];
		
		rep(i, 0, m){
			rep(j, 0, n){
				scanf("%d", &ma[i][j]);
			}
		}
		rep(i, 0, l){
			rep(j, 0, n){
				scanf("%d", &le[i][j]);
			}
		}
		scanf("%d %d %d", &m, &l, &n);
		if(ma[m-1][n-1]==le[l-1][n-1]) puts("Empate");
		else if(ma[m-1][n-1]>le[l-1][n-1]) puts("Marcos");
		else puts("Leonardo");
	}

	
	return 0;
	
}

