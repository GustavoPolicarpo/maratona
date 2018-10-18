// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: DJ da Computação
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1265

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int solve(ll n, ll k){
	ll t = 1, at = n;
	while(k>=at*t){
		k-=at*t;
		t++;
		at*=n;
	}	
	int num = k/t; k -= t*num;
	vector <ll> xuaca;
	while(num){
		xuaca.pb(num%(n));
		num/=(n);
	}
	while(xuaca.size()<t) xuaca.pb(0);
	reverse(xuaca.begin(), xuaca.end());
	return xuaca[k];
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	/*
	0
	1
	2
	00
	01
	02
	10
	11
	12
	20
	21
	22
	000
	001
	*/
	
	//0 1 2 -> 3 = 3*1
	//0 0 0 1 0 2 1 0 1 1 1 2 2 0 2 1 2 2 -> 18 = 3*3*2
	//0 0 0 0 0 1 0 0 2 ... -> 81 = 3*3*3*3
	// ABC AAABACBABBBCCACBCC AAAAABAACABAABBABC
	/*
	0 0 0 0
	0 0 0 1
	0 0 1 0
	
	0 0 0
	0 0 1
	0 0 2
	0 1 0
	*/
	
	int N, Q;
	while(cin >> N >> Q and N){
		vector <string> vs; string s;
		rep(i, 0, N){
			cin >> s;
			vs.pb(s);
		}
		ll k;
		while(Q--){
			cin >> k;
			cout << vs[solve(N, k-1)] << '\n';
		}
		puts("");
	}
	return 0;
} 
