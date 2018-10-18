// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jogatina UFPR
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2543

#include <bits/stdc++.h>

#define pb push_back 
#define mp make_pair 
#define F first 
#define S second 
#define rep(i, a, b) for(int i=a; i<b; i++)

using namespace std;

typedef pair <int, int> ii;


int main(){
	
	int n, m;
	while(scanf("%d %d", &n, &m) !=EOF){
		int cnt=0, a, b;
		rep(i, 0, n){
			scanf("%d %d", &a, &b);
			if(a==m && b==0) cnt++;
		}
		
		printf("%d\n", cnt);
		
	}

	
	return 0;
	
}

