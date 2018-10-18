// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Montanha-Russa
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2547

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;


int main(){

	int n, m, o;
	
	while(scanf("%d %d %d", &n, &m, &o)!=EOF){
		int cnt=0, aux;
		while(n--){
			scanf("%d", &aux);
			if(aux>=m && aux<=o) cnt++;
		}
		
		cout << cnt << '\n';
		
	
	}


	return 0;

}
