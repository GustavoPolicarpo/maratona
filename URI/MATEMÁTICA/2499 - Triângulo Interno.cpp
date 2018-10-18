// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Triângulo Interno
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2499

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;

const ll mod = 1e9+7;
const ull MAX = mod*mod*2;
const int INF = 0x3f3f3f3f;

void scanint(ll &x){
    register ll ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}


int main(){
	
	ll S, N, M, C1, C2, C3;
	
	while(scanf("%lld %lld %lld", &S, &N, &M) !=EOF){
		
		if(!(S+M+N)) break;
		
		scanf("%lld %lld %lld", &C1, &C2, &C3);
		ll x=S*(abs(C3-C2))*C1/((N+1)*(M+1));
		
		printf("%lld\n", x);
		
	}
	
	return 0;
	
}
