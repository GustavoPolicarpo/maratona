// Author: Gustavo Policarpo
// Name: Cachecol da Vovó Vitória
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2439

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define REP(i,a,b) for( int i = (int) a; i <= (int) b; i++ )
#define PER(i,a,b) for( int i = (int) a; i >= (int) b; i-- )
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
 
using namespace std;
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;
typedef pair <double, ii> iii;

const int MAX = 2e3+3;
const int mod = 1e9+7;

const int TAM = 3;
struct Matriz{
	ll mat[TAM][TAM];
};

Matriz identidade;
ll N;

Matriz multiplica(Matriz A, Matriz B){
	Matriz C;
	rep(i, 0, TAM) rep(j, 0, TAM){
		C.mat[i][j]=0;
		rep(k, 0, TAM)
			C.mat[i][j]=((C.mat[i][j]%mod+((A.mat[i][k]%mod)*(B.mat[k][j]%mod))%mod));
	}
	return C;
}

Matriz fastExp(Matriz base, ll p){
	if(p==0) return identidade;
	Matriz ret=fastExp(base, p/2);
	ret=multiplica(ret, ret);
	if(p&1) ret=multiplica(ret, base);
	return ret;
}

int main(){

	rep(i, 0, TAM) rep(j, 0, TAM){
		if(i==j) identidade.mat[i][j] = 1;
		else identidade.mat[i][j] = 0;
	}
	
	Matriz base;
	base.mat[0][0] = 2; base.mat[0][1] = 2; base.mat[0][2] = 0;
	base.mat[1][0] = 2; base.mat[1][1] = 3; base.mat[1][2] = 0;
	base.mat[2][0] = 4; base.mat[2][1] = 5; base.mat[2][2] = 0;
	
	cin >> N;
	
	if(N==1){
		cout << 12 << '\n';
		return 0;
	}
	
	base = fastExp(base, N-1);
	ll ans = (base.mat[2][0]*6 + base.mat[2][1]*6)%mod;
	
	cout << ans << '\n';
	

 
    return 0;
}
