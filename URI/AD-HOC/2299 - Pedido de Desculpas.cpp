// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pedido de Desculpas
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2299

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;



int pd[60][1010], custo[60], valor[60], N, C, z=1;

int solve(int i, int c){
	
	if(i==C) return 0;
	if(pd[i][c]!=-1) return pd[i][c];
	
	int ret=solve(i+1, c);
	if(c>=custo[i])
		ret=max(ret, solve(i+1, c-custo[i])+valor[i]);
	
	return pd[i][c]=ret;

}
int main(){
	
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(1){
		scanint(N), scanint(C);
		if(!N) break;
		
		rep(i, 0, C){
			rep(j, 0, N+1) pd[i][j]=-1;
			scanint(custo[i]);
			scanint(valor[i]);
		}
		
		printf("Teste %d\n", z++);
		printf("%d\n\n", solve(0, N));
	}

	return 0;
	
}

