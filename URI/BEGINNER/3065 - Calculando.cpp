// Author: Gustavo Policarpo
// Name: Calculando
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3065

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
typedef pair <ii, int> iii;
const int MAX = 2e3+3;
const int mod = 1e9+7;


int main(){
	
	int T, teste = 1;
	while(cin >> T and T){
		int s=0; char op='+'; int n;
		rep(i, 0, T){
			if(i) cin >> op;
			cin >> n;
			if(op=='+') s = s+n;
			if(op=='-') s = s-n;
		}
		printf("Teste %d\n%d\n\n", teste++, s);
	}
	

	return 0;
}
