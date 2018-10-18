// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Dígitos
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2867

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
	
    int T; cin >> T;
    while(T--){
    	int N, M; cin >> N >> M;
    	//log(N^M) = M*log(N)
    	cout << int(M*log10(N)+1) << '\n';
	}
	

	return 0;
} 
