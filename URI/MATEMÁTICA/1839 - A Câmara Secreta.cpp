// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Câmara Secreta
// Nível: 4
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1839

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int N, M, mod = 1e9+7;
char mat[55][55];
int sum[55][55];
ll C[55*55][55*55];

void Pascal(){
	C[0][0] = 1;
	rep(i, 1, 51*51){
		C[i][0] = 1;
		rep(j, 1, i+1){
			C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
		}
	}
}


int main(){
	
	Pascal();
	
	cin >> N >> M;
	rep(i, 1, N+1) rep(j, 1, M+1) cin >> mat[i][j];
	
	rep(i, 1, N+1) rep(j, 1, M+1){
		sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (mat[i][j]=='#');
	}
	
	int xa, ya, xb, yb, qr, qt;
	while(cin >> xa >> ya >> xb >> yb){
		qt = (xb-xa+1)*(yb-ya+1);
		qr = sum[xb][yb] - sum[xb][ya-1] - sum[xa-1][yb] + sum[xa-1][ya-1];
		cout << (C[qt][qr]-1+mod)%mod << '\n';
	}
		
	
	return 0;
} 
