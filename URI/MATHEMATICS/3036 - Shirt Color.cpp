// Author: Gustavo Policarpo
// Name: Shirt Color
// Level: 9
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3036

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
 
using namespace std;
 
typedef long long int ll;
typedef pair<int,int> ii;
	

bool isPrime(int n){
	if(n<=1) return false;
	if(n==2) return true;
	int f = sqrt(n);
	rep(i, 2, f+1) if(n%i==0) return false;
	return true;
}

int main(){
	
	double v; cin >> v;
	double c = 3e8, l0 = 700;
	double l1 = (sqrt((c-v)/(c+v))-1)*l0+l0;
	
	//debug(l1);
	if(l1 < 400) puts("invisivel");
	else if(l1 < 425) puts("violeta");
	else if(l1 < 445) puts("anil");
	else if(l1 < 500) puts("azul");
	else if(l1 < 575) puts("verde");
	else if(l1 < 585) puts("amarelo");
	else if(l1 < 620) puts("laranja");
	else if(l1 < 750) puts("vermelho");
	else puts("invisivel");
	
	
	return 0;
}
