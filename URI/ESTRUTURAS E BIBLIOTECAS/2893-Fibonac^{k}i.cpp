// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fibonac^{k}i
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2893

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;


#define mod 1000007

int ini[200020], sum[200020];

int main(){
	
	int T; cin >> T;
	while(T--){
		int K, N; cin >> K >> N;
		int i = 0, j = 0;
		while(j<N){
			if(j<K){
				ini[j++] = j-1;
				if(j==1) sum[j-1] = ini[j-1];
				else sum[j-1] = (sum[j-2] + ini[j-1])%mod;
			}else{
				ini[j++] = (sum[j-2]-(j-1==K ? 0 : sum[i++])+mod)%mod;
				if(j==1) sum[j-1] = ini[j-1];
				else sum[j-1] = (sum[j-2] + ini[j-1])%mod;
			}
		}
		cout << ini[j-1] << '\n';
	}

	return 0; 
}	
	

