// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Promoção
// Nível: 6
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1624

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;


const ll mod = 1000000007;


int valor[101], custo[101];
int N, P;

int solve(int i, int c){
	
	if(i==N) return 0;
	
	int np = 0, p = 0;//nao pegando e pegando
	np = solve(i+1, c);
	if(c>=custo[i]) p = solve(i+1, c-custo[i])+valor[i];
	
	return max(np, p);
}

int main(){
	
	
	while(cin >> N and N){
		
		rep(i, 0, N) cin >> valor[i] >> custo[i];
		cin >> P;
		
		cout << solve(0, P)	<< '\n';
	}
	
	
	
			
	return 0;
}
