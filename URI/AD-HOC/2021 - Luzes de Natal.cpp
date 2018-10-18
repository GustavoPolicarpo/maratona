// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Luzes de Natal
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2021

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

int main()
{
	int M, N, P;
	while(scanf("%d %d %d", &M, &N, &P) and M+N+P){
		int out=0, aux;
		while(P--){
			scanf("%d", &aux);
			if(aux%N==0) out++;
			else out+=N-aux%N+1;
		}
		printf("Lights: %d\n", out);	
	}
}
