// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Macaco-prego
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2188

#define gc getchar_unlocked
#include<bits/stdc++.h>

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
#define error 1e-4

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	int N, z=1, X, Y, U, V, x, y, u, v; 
	while(1){
		//scanf("%d", &N);
		scanint(N);
		if(!N) break;
		x=-INF, y=INF, u=INF, v=-INF;
		printf("Teste %d\n", z++);
		while(N--){
			//scanf("%d %d %d %d", &X, &Y, &U, &V);
			scanint(X), scanint(Y), scanint(U), scanint(V),
			x=max(x, X), y=min(y, Y),
			u=min(u, U), v=max(v, V); 
		}
		if(x<u && y>v) printf("%d %d %d %d\n\n", x, y, u, v);
		else printf("nenhum\n\n");
	}
	
return 0;

}

