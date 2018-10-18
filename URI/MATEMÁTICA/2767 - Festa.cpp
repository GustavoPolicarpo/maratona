// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Festa
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2767

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS

#include<bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x);

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )

void scanint(register int &x){
    register int ccc = gc(); x = 0;
    if(ccc==EOF) exit(0);
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

using namespace std;

typedef long long int ll;


int F[100010], mark[100010];


int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	register int aux, cnt = 1;
	register int N, M, K, p; ll ans;
	
	while(42){
		scanint(N);
		scanint(M);
		scanint(K);
		ans = 0, cnt++;
		rep(i, 0, N){
			scanint(aux);
			p  = aux%K;
			if(mark[p]==cnt) F[p]++;
			else mark[p] = cnt, F[p] = 1;
		}
		rep(i, 0, M){
			scanint(aux);
			p = (K-aux%K)%K;
			if(mark[p]!=cnt) continue;
			ans = ans+F[p];
		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
