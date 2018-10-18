// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Recuperação
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2135

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
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, string > ii;
typedef pair < double, int > iii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main()
{
	int N, z=1, n[105], soma, ps; bool yep;
	while(scanf("%d", &N) !=EOF){
		soma=0; yep=false;
		rep(i, 0, N){
			scanf("%d", &n[i]);
			if(!yep && soma==n[i]){
				ps=n[i], yep=true;
			}
			else soma+=n[i];
		}
			
		printf("Instancia %d\n", z++);
		if(yep) printf("%d\n", ps);
		else printf("nao achei\n");
		printf("\n");
	}
	
			
return 0;
}
