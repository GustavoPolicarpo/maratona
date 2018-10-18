// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Subsets do Dabriel
// Nível: 5
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2777

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )

using namespace std;
typedef long long int ll;

struct Matriz{
	ll mat[5][5];
};

Matriz identidade;
ll mod = 1000000007;

Matriz multiplica(Matriz A, Matriz B){
	Matriz C;
	rep(i, 0, 5)
		rep(j, 0, 5){
			C.mat[i][j]=0;
			rep(k, 0, 5)
				C.mat[i][j]=(C.mat[i][j]+(A.mat[i][k]*B.mat[k][j])%mod)%mod;
		}
	return C;
}

Matriz fastExp(Matriz base, ll p){
	if(p<=0) return identidade;
	Matriz ret=fastExp(base, p/2);
	ret=multiplica(ret, ret);
	if(p&1) ret=multiplica(ret, base);
	return ret;
}

int main(){
	
	ll val[] = {1, 2, 2, 3, 4}, N;
	while(scanf("%lld", &N)!=EOF){
		
		if(N<=5){
			printf("%lld\n", val[N-1]);
			continue;
		}
		
		Matriz rec;
		rep(i, 0, 5) rep(j, 0, 5) identidade.mat[i][j] = (i==j ? 1 : 0), rec.mat[i][j] = 0;
		rec.mat[0][4] = 1;
		rec.mat[1][0] = 1;
		rec.mat[2][1] = 1;
		rec.mat[3][2] = 1;
		rec.mat[4][3] = 1;
		rec.mat[4][4] = 1;
		
		rec = fastExp(rec, N-5); ll ans = 0;
		rep(i, 0, 5) ans = (ans+(val[i]*rec.mat[i][4])%mod)%mod;
		
		printf("%lld\n", ans);
		
	}
	
    return 0;
}
