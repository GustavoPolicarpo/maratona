// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Aproveite a Oferta
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2896

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

int main()
{
	
	int T; cin >> T;
	while(T--){
		int N, K; cin >> N >> K;
		cout << N/K + N%K << '\n';	
	}
	
	return 0;
}
