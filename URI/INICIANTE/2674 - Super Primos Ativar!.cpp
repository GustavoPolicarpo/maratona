// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Super Primos: Ativar!
// Nível: 2
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2674

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


bool isPrime(int n){
	if(n==1) return 0;
	if(n==2) return 1;
	if(n%2==0) return 0;
	int fim = sqrt(n);
	for(int i=3; i<=fim; i+=2){
		if(n%i==0) return 0;
	}
	return 1;
}
int main(){
	
	int N;
	
	while(scanf("%d", &N) !=EOF){
		
	
		
		if(!isPrime(N)) puts("Nada");
		else{
			bool yep=true;
			while(N){
				if(!isPrime(N%10)){
					yep = false;
					break;
				}
				N/=10;
			}
			yep? puts("Super"):puts("Primo");
		}
	}
	
	return 0;
	
}
