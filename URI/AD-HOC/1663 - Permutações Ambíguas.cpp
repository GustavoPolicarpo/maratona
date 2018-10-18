// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Permutações Ambíguas
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1663

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
typedef pair < ii, int > iii;


int v[100010], c[100010];
int main()
{
	
	int n;
	while(scanf("%d", &n) and n){
		
		rep(i, 1, n+1){
			scanf("%d", &v[i]);
			c[v[i]]=i;
		}
		
		int yep=0;
		rep(i, 1, n+1){
			if(c[i]!=v[i]){
				yep=1;
				break;
			}
		}
		
		yep?puts("not ambiguous"):puts("ambiguous");
		
	}
	
	return 0;
	
}
