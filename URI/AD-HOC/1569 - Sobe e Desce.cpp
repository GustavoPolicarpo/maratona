// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sobe e Desce
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1569

#pragma comment(linker, "/stack:200000000")                                     
#pragma GCC optimize("Ofast")                                                   
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")   
#define _CRT_SECURE_NO_WARNINGS          
#define gc getchar
#define pc(x) putchar(x);

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

void scanint(register int &x){
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

int pos[1000010];
int way[101];
int save[101], cnt = 1;

int main(){
	
	register int T; 
	register int u, v;
	register int a, b, c;
	register int player, win;
	
	scanint(T);
	while(T--){
		
		scanint(a), scanint(b), scanint(c);
		
		cnt++; 
		while(b--){
			scanint(u), scanint(v);
			save[u] = cnt;
			way[u] = v;
		}
		
		rep(i, 1, a+1) pos[i] = 1;
		player = 1; win = 0;
		while(c--){
			scanint(u);
			if(win) continue;
			pos[player]+=u;
			if(save[pos[player]]==cnt) pos[player] = way[pos[player]];
			if(pos[player]>=100){
				pos[player] = 100;
				win = 1;
			}
			player++;
			if(player==a+1) player = 1;
		}
		
		rep(i, 1, a+1){
			printf("Position of player %d is %d.\n", i, pos[i]);
		}
		
		
	}

	
	
	return 0;
}
