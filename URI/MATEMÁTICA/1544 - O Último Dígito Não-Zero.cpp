// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Último Dígito Não-Zero
// Nível: 5
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1544

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


//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int solve(int n, int m){
	int last=1, d2=0;
	rep(i, n-m+1, n+1){
		int aux=i;
		while(aux%2==0) d2++, aux/=2;
		while(aux%5==0) d2--, aux/=5;
		last=(last*aux)%10;
	}
	
	rep(i, 0, d2) last=(last*2)%10;
	d2*=-1;
	rep(i, 0, d2) last=(last*5)%10;
	
	return last;
}
int main()
{

	int n, m;
	while(scanf("%d %d", &n, &m) !=EOF){
		printf("%d\n", solve(n, m));
	}

	return 0;
	
}
