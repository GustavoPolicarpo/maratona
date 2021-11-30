// Author: Gustavo Policarpo
// Name: Helping Uncle Cláudio
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2158

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


int main()
{
	ll p, h, v, a, f, z=1;
	while(scanf("%lld %lld", &p, &h) !=EOF){
		printf("Molecula #%lld.:.\n", z++);
		f=p+h;
		a=(p*5+h*6)/2;
		v=2-f+a;
		printf("Possui %lld atomos e %lld ligacoes\n\n", v, a);
	}

return 0;
}


