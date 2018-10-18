// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pirâmide
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2785

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int n;
int mat[101][101];
int pd[101][101];

int val(int i, int j, int k){
	int sum = 0;
	while(i<=j) sum+=mat[k][i++];
	return sum;
}

int solve(int i, int j, int k){
	if(k==-1) return 0;
	if(pd[i][j]!=-1) return pd[i][j];
	return pd[i][j] = min(solve(i+1, j, k-1), solve(i, j-1, k-1))+val(i, j, k);
}

int main(){
	
	cin >> n;
	rep(i, 0, n) rep(j, 0, n) cin >> mat[i][j];
	memset(pd, -1, sizeof pd);
	cout << solve(0, n-1, n-1) << '\n';
	
	return 0;
}
