// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Reinauguração do CEI
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2556

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;

int main()
{
	
	int n;
	
	while(scanf("%d", &n)!=EOF){
		int v[n];
		rep(i, 0, n) scanf("%d", &v[i]);
		sort(v, v+n);
		
		printf("%d %d\n", n/2, v[n/2]-v[n/2-1]);
		
	}
	
	
	

	return 0;
	
}
