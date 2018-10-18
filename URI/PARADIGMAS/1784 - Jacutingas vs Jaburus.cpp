// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jacutingas vs Jaburus
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1784

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < ll, int > ii;

int main(){
	
	
	int T; cin >> T;
	rep(z, 1, T+1){
		int N; cin >> N;
		int P[N], C[N], pos[N];
		rep(i, 0, N) cin >> P[i];
		rep(i, 0, N) cin >> C[i];
		rep(i, 0, N) pos[i] = i;
		int ans = 0x3f3f3f3f;
		
		sort(P, P+N);
		reverse(P, P+N);
		sort(C, C+N);
		reverse(C, C+N);
		
		do{
			int aux = 0;
			rep(i, 0, N){
				aux = max(aux, P[i]*C[pos[i]]/__gcd(P[i], C[pos[i]]));
				if(aux>=ans) break;
			}
			ans = min(ans, aux);
		}while ( next_permutation(pos, pos+N) );
		
		printf("Caso #%d: %d\n", z, ans);
	}
	
	return 0;
}
