// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: É Hora do Duelo!
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1896

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

struct use{
	int a, d, h;
};
vector <use> v;
int n, yep;

void brute(int i, int a, int d, int h, int q){
	if(a==v[0].a && d==v[0].d && h==v[0].h && q>=2){
		yep = true;
		return;
	}
	if(i==v.size() || a>v[0].a || d>v[0].d || h>v[0].h) return;
	brute(i+1, a+v[i].a, d+v[i].d, h+v[i].h, q+1);
	brute(i+1, a, d, h, q);
}

int main(){
	
	cin >> n; use aux;
	rep(i, 0, n+1){
		cin >> aux.a >> aux.d >> aux.h;
		v.pb(aux);
	}
	
	brute(1, 0, 0, 0, 0);
	if(yep) puts("Y");
	else puts("N");
	
	return 0;
} 
