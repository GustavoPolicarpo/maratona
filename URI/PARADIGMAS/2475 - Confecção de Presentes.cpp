// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Confecção de Presentes
// Nível: 6
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2475

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


ll pd[10010][505];
ll n[10010], custo[10010];
int save[10010];
const ll LINF = 1LL << 60;
int P, A;

ll solve(int i, int a){
	
	if(i>=P+1) return 0;
	if(a==1) return (custo[P]-custo[i-1])*(P-i+1);
	if(pd[i][a]) return pd[i][a];
	
	
	ll ret=LINF;
	
	int ini=i, fim=P-a+1;
	
	if(save[i-1]) ini=save[i-1];
	if(save[i]) fim=save[i];
	
	for(int j=ini; j<=fim; j++){
		ll aux = solve(j+1, a-1) + (custo[j]-custo[i-1])*(j-i+1);
		if(aux<ret) ret=aux, save[i]=j;
		if(ret*2<aux) break;
	}
	
	return pd[i][a]=ret;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	scanf("%d %d", &P, &A);
	
	rep(i, 0, P) scanf("%lld", &n[i]);
	
	custo[1]=n[0];
	rep(i, 2, P+1) custo[i]=custo[i-1]+n[i-1];
	
	if(A>=P){
		printf("%lld\n", custo[P]);
		return 0;
	}
	
	printf("%lld\n", solve(1, A));
	
	return 0;
	
}
