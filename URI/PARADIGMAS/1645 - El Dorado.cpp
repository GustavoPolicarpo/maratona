// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: El Dorado
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1645

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

int N[100], n, k; ll out, pd[100][100];

ll solve(int i, int c)
{
	if(c==k) return 1;
			
	if(pd[i][c]!=-1) return pd[i][c];
	
	ll ret=0;
	for(int j=i+1; j<=n-k+c; j++){
		if(N[j]>N[i])
			ret+=solve(j, c+1);	
	}
	return pd[i][c]=ret;
}

int main()
{
	while(scanf("%d %d", &n, &k) && n+k){
		memset(pd, -1, sizeof(pd));
		rep(i, 0, n)
			scanf("%d", &N[i]);
			
		out=0;
		rep(i, 0, n-k+1)
			out+=solve(i, 1);
			
		printf("%lld\n", out);
	}
						
return 0;
}
