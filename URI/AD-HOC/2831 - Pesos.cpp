// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pesos
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2831

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
 


int main(){
	
	
	int n; cin >> n;
	vector <int> v; int aux = 0;
	v.pb(aux);
	rep(i, 0, n){
		cin >> aux;
		v.pb(aux);
	}
	
	sort(v.begin(), v.end());
	
	rep(i, 0, v.size()-1){
		if(v[i+1]-v[i]>8){
			puts("N");
			return 0;
		}
	}
	
	puts("S");
	
	return 0;
}  
