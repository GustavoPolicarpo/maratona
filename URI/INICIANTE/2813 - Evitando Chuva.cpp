// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Evitando Chuva
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2813

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<string, string> ii;



int main(){
	
	int n; cin >> n;
	string a, b; int qa = 0, qb = 0, aa = 0, bb = 0;
	
	rep(i, 0, n){
		cin >> a >> b;
		if(a=="chuva" && aa==0) qa++, bb++;
		else if(a=="chuva") aa--, bb++;
		
		if(b=="chuva" && bb==0) qb++, aa++;
		else if(b=="chuva") bb--, aa++;
	}
	
	cout << qa << " " << qb << '\n';
	
		
	return 0;
}
