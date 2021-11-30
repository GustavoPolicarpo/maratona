// Author: Gustavo Policarpo
// Name: Final Thesis of Christmas...
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2930

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;


int main(){

	int E, D; cin >> E >> D;
	if(D-E>=3){
		puts("Muito bem! Apresenta antes do Natal!");
	}else{
		if(E<=D){
			puts("Parece o trabalho do meu filho!");
			if(D+2<=24){
				puts("TCC Apresentado!");
			}else{
				puts("Fail! Entao eh nataaaaal!");
			}
		}else{
			puts("Eu odeio a professora!");
		}
	}
			
	return 0;
}
