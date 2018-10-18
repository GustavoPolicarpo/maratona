// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Trocando Presentes
// Nível: 5
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2734

#pragma comment(linker, "/stack:200000000")                                     
#pragma GCC optimize("Ofast")                                                   
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")   
#define _CRT_SECURE_NO_WARNINGS          
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;



int val[202], N, sum;
int pd[202][1010][202], cnt = 1;

int solve(int i, int s, int q){
	if(i==N*2){
		if(q==N) return abs(s-(sum-s));
		return 0x3f3f3f3f;
	}
	if(pd[i][s][q]!=-1) return pd[i][s][q];
	int ret = solve(i+1, s+val[i], q+1);
	ret = min(ret, solve(i+1, s, q));
	return pd[i][s][q] = ret;
}

int main(){
	
	//cout << sizeof(pd);
	int T; cin >> T;
	while(T--){
		scanf("%d", &N); sum = 0;
		rep(i, 0, N) scanf("%d", &val[i]), sum+=val[i];
		rep(i, 0, N) scanf("%d", &val[i+N]), sum+=val[i+N];
		rep(i, 0, N*2) rep(j, 0, sum+2) rep(k, 0, N*2) pd[i][j][k] = -1;
		cout << solve(0, 0, 0) << '\n';
	}
	
	
	return 0;
}
