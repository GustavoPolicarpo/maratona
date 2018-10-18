// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Dados
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2790

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

int N, d[100010];

int val(int a, int b){
	if(a==b) return 0;
	if(a+b==7) return 2;
	return 1;
}

int main(){
	
	scanf("%d", &N);
	rep(i, 0, N) scanf("%d", &d[i]);
	
	int ans = 0x3f3f3f3f;
	rep(z, 1, 7){
		int aux = 0;
		rep(i, 0, N)
			aux+=val(d[i], z);
		ans = min(ans, aux);
	}
	
	cout << ans << "\n";
	
	return 0;
}
