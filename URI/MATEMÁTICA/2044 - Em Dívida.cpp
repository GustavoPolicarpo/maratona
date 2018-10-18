// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Em Dívida
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2044

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
const int mod = 1e9 + 7;
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int main(){
	int N;
	while(scanf("%d", &N)){
		if(N==-1) break;
		int sum=0, out=0, aux;
		rep(i, 0, N){
			scanf("%d", &aux);
			sum+=aux;
			if(sum%100 == 0){
				out++;
				sum=0;
			}
		}
		printf("%d\n", out);
	}
}
