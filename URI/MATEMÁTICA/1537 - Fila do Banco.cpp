// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fila do Banco
// Nível: 5
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1537

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

#define mod 1000000009
int N;
ll fat[100001];

int main()
{
	fat[3]=1;
	for(ll i=4; i<100001; i++)
		fat[i]=(fat[i-1]*i)%mod;
	
	while(scanf("%d", &N) and N){
		printf("%lld\n", fat[N]);
	}
}
