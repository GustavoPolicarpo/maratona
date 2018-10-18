// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Apaixonado por Binário
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1705

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < ll, int > ii;

vector <int> primo;
int eh[1000010];

void crivo(){
	int fim1 = 1000010, fim2 = sqrt(fim1);
	for(int i=3; i<fim1; i+=2) eh[i] = 1;
	for(int i=3; i<fim2; i+=2) if(eh[i])
		for(int j=i*i; j<=fim1; j+=i)
			eh[j] = 0;
	
	primo.pb(2);
	for(int i=3; i<fim1; i+=2) if(eh[i])
		primo.pb(i);
	
}

vector <ii> pqt;
map<ll, ll> ans;

void sol(int p, ll val, ll n){
	if(p==pqt.size()){
		if(ans.count(val)) ans[val] = min(ans[val], n);
		else ans[val] = n;
		return;
	}
	sol(p+1, val, n);
	rep(i, 0, pqt[p].S){
		val*=pqt[p].F;
		sol(p+1, val, n);
	}
	return;
}

void all_div(ll n){
	int i = 0; ll aux = n; pqt.clear();
	while(aux!=1 && i<primo.size()){
		if(primo[i]*primo[i]>aux) break;
		int qt = 0;
		while(aux%primo[i]==0){
			qt++;
			aux/=primo[i];
		}
		if(qt) pqt.pb(ii(primo[i], qt));
		i++;
	}
	if(aux>1) pqt.pb(ii(aux, 1));
	sol(0, 1, n);
}

void all_numbers(ll n){
	if(n>=1000000000000LL) return;
	all_div(n);
	all_numbers(n*10);
	all_numbers(n*10+1);
	return;
}

int main(){
	
	crivo();
	all_numbers(1);
	ll n;
	while(scanf("%lld", &n)!=EOF){
		if(ans.count(n)){
			printf("%lld\n", ans[n]);
		}else{
			puts("-1");
		}
	}
	
	return 0;
}
