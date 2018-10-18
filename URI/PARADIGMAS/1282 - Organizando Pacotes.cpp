// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Organizando Pacotes
// Nível: 9
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1282

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)

typedef long long int ll;

const ll LINF = 1LL<<60;

ll pd[1010][1010], custo[1010][1010];
int n, k, ponto[1010], peso[1010], save[1010][1010];

ll solve(int i, int c){
	if(i==n) return 0;
	if(pd[i][c]!=-1) return pd[i][c];
	if(c==1) return pd[i][c]=custo[i][n-1];
	
	ll ret=LINF;
	int ini=i, fim=n-c+1, best=0;
	if(i && save[i-1][c]) ini=save[i-1][c];
	if(save[i][c-1]) fim=save[i][c-1]+1;
	
	//cout << i << " " << ini << " " << fim << " " << n-c+1 << '\n';
	
	rep(j, ini, fim){
		ll aux=solve(j+1, c-1)+custo[i][j];
		if(ret > aux){
			ret=aux;
			best=j;
		}
	}
	
	save[i][c]=best;
	
	return pd[i][c]=ret;
	
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d %d", &n, &k) !=EOF){
		
		rep(i, 0, n){
			scanf("%d %d", &ponto[i], &peso[i]);
			rep(j, 0, k+1){
				pd[i][j]=-1;
				save[i][j]=0;
			}
		}	rep(j, 0, k+1){
				pd[n][j]=-1;
				save[n][j]=0;
		}
	
		for(int i=n-1; i>=0; i--){
			custo[i][i]=0;
			for(int j=i-1; j>=0; j--){
				custo[j][i]=custo[j+1][i]+ll(peso[j])*(ponto[i]-ponto[j]);
			}
		}
		
		ll ans=solve(0, k);
		
		printf("%lld\n", ans);
	
	}
	
	return 0;
	
}
