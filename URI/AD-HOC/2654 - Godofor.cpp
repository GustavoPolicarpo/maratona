// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Godofor
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2654


#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;


struct use{
	string s;
	int p, k, m;
};

bool cmp(use a, use b){
	if(a.p!=b.p) return a.p>b.p;
	if(a.k!=b.k) return a.k>b.k;
	if(a.m!=b.m) return a.m<b.m;
	return a.s<b.s;
}

int main(){
	
	int N; cin >> N; use aux;
	vector <use> v;
	
	while(N--){
		cin >> aux.s >> aux.p >> aux.k >> aux.m;
		v.pb(aux);
	}
	
	sort(v.begin(), v.end(), cmp);
	
	cout << v[0].s << '\n';
	
	
	return 0;
}
