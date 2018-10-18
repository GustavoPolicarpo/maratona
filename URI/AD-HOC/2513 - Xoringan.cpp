// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Xoringan
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2513

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)

typedef long long int ll;
typedef unsigned long long int ull;

const ull mod = 1e9+7;
const ull MAX = mod*mod;

int N; ull v[1010];

void scanint(ull &x){
    register ull ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

void sum(ull &ans, ull add){
	if(add >= MAX) add%=mod;
	ans+=add;
	if(ans >= MAX) ans%=mod;
}
int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d", &N) !=EOF){
		
		if(N<=0) break;
		
		rep(i, 1, N+1) scanint(v[i]);
		
		ull ans=0, atual;
		for(int i=1; i<=N; i++){
			
			atual=v[i], sum(ans, atual);
			
			for(int j=i+1; j<=N; j++){
				
				atual^=v[j], sum(ans, atual);
				
			}
		}
		
		if(ans >= mod) ans%=mod;
		
		printf("%llu\n", ans);
		
	}
	
	return 0;
	
}
