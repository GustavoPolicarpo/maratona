// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Guerreiros Etruscos Nunca...
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1308

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	int N; cin >> N; ull n;
	while(N--){	
		scanf("%llu", &n);
		double aux, s, delta;
		aux=-2.0*n;
		delta=1.0-4.0*aux;
		s=(-1.0+sqrt(delta))/2.0;
		int out=s;
		printf("%d\n", out);
	}

return 0;
}
