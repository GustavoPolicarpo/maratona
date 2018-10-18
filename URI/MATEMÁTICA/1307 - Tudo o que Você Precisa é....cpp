// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tudo o que Você Precisa é...
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1307

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int main()
{	
	int N; cin >> N;
	char in[30]; int a, b, aux, z=1;
	rep(i, 0, N){
		scanf("%s", &in);
		a=strtol(in, NULL, 2);
		scanf("%s", &in);
		b=strtol(in, NULL, 2);
		aux=__gcd(a, b);
		if(aux==1) printf("Pair #%d: Love is not all you need!\n", z++);
		else printf("Pair #%d: All you need is love!\n", z++);
	}
		
return 0;
}
