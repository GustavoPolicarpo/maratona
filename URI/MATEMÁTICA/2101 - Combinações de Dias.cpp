// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Combinações de Dias
// Nível: 5
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2101

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
#define error 1e-8

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;


ll mdc(ll a, ll b) 
{ 
	if (!a) return b; 
	return mdc(b%a, a); 
}
ull mmc(ll a, ll b) 
{ 
	ull ret=(a*(b/mdc(a,b)))%1713371337; 
	return ret;
}

int main()
{
	ll D1, D2;
	while(scanf("%lld %lld", &D1, &D2) and D1+D2){
		ull out=mmc(D1, D2);
		printf("%llu\n", out);
	}
	
return 0;
}
