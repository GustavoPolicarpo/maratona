// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: {soma+=i++} até N
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1568

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
typedef pair < int, int > ii;
typedef pair < double, int > iii;

#define MAX 3000000  //MAXIMO VALOR

int isprime[MAX+1];
ll primo[MAX+1], cnt=1, N, aux;


inline void gp(){
	primo[0]=2;
	memset(isprime, 1, sizeof(isprime));
	for(ll i=3; i<=MAX; i+=2) if(isprime[i]) {
		primo[cnt++]=i;
		
		for(ll j=i*i; j<=MAX; j+=i){
			isprime[j] = 0;
		}
	}
}

inline ll solve(ll N){
	int j=1, cont=0, out=1;
	while(aux>1 && j<cnt){
		cont=0;
		while(aux%primo[j]==0){
			aux/=primo[j];
			cont++;
		}
		j++;
		out*=(cont+1);
	}
	if(aux>1) out*=2;

	return out;
}
int main()
{	
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
	gp();
	while(scanf("%lld", &N) !=EOF){
		
		aux=N;
		while(aux%2==0) aux/=2;
		int out=solve(aux);
		
		printf("%d\n", out);
	}
	
return 0;
}


