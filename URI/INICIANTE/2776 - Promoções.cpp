// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Promoções
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2776

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int N, M, dp[2002];
ii itens[1001];
int morreu[101];

bool cmp(ii a, ii b){
	return a.S*b.F > b.S*a.F;
}

int main(){
	
	while(scanf("%d %d", &N, &M)!=EOF){
		rep(i, 1, M+1) dp[i] = -1; rep(i, 0, 101) morreu[i] = 0;
		rep(i, 0, N) scanf("%d %d", &itens[i].F, &itens[i].S);
		sort(itens, itens+N, cmp);
		rep(i, 0, N){
			if(morreu[itens[i].F]) continue;
			int yep = false;
			for(int j=itens[i].F; j<=M; j++){
				if(dp[j-itens[i].F]==-1) continue;
				if(dp[j] < dp[j-itens[i].F]+itens[i].S){
					yep = true;
					dp[j] = dp[j-itens[i].F]+itens[i].S;
				}
			}
			if(!yep) morreu[itens[i].F] = true;
		}
		printf("%d\n", dp[M]);
	}
	
	return 0;
}
