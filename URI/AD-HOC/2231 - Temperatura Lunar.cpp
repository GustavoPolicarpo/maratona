// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Temperatura Lunar
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2231

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
#define MAXN 100001
#define mod 1000000007
#define error 1e-7

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
	int N, M, z=1;
	while(1){
		scanint(N), scanint(M);
		if(!(N+M)) break;
		printf("Teste %d\n", z++);
		int minimo=INF, maximo=-INF, atual=0;
		int n[N];
		rep(i, 0, N) scanint(n[i]);//scanf("%d", &n[i]);
		rep(i, 0, M) atual+=n[i];
		minimo=atual/M, maximo=atual/M;
		rep(i, M, N){
			atual-=n[i-M], atual+=n[i];
			int aux=atual/M;
			if(aux < minimo) minimo=aux;
			if(aux > maximo) maximo=aux;

		}
		printf("%d %d\n\n", minimo, maximo);
	}
	
	return 0;	
}



