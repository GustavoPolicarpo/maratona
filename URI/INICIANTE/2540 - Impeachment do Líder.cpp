// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Impeachment do Líder
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2540

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
		double cnt=0, cmp=2.0/3.0, aux;
		rep(i, 0, n){
			cin >> aux;
			cnt+=aux;
		}
		cnt/=n;
		if(cnt>=cmp) puts("impeachment");
		else puts("acusacao arquivada");
	}

	
	return 0;
	
}

