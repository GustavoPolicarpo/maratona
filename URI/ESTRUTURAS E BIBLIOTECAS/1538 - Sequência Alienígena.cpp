// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sequência Alienígena
// Nível: 5
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1538

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define INF 0x3F3F3F3F3F
#define mod 10000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


int main(){
	
	ll N;
	while(scanf("%lld", &N) and N){
		N*=N;
		vector <ll> num;
		while(N){
			num.pb(N%4);
			N/=4;
		}
		reverse(num.begin(), num.end());
		rep(i, 0, num.size()){
			printf("%c", num[i]+'A');
		}
		printf("\n");
	}
	return 0;
}
