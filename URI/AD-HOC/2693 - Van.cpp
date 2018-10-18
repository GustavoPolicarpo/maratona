// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Van
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2693

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define pb push_back
#define F first
#define S second

using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;

struct use{
	string name;
	char region;
	int distance;
};

bool cmp(use a, use b){
	if(a.distance!=b.distance) return a.distance < b.distance;
	if(a.region!=b.region) return a.region < b.region;
	return a.name < b.name;
}

int main(){
	
	int Q;
	while(cin >> Q){
		vector <use> v; use aux;
		rep(i, 0, Q){
			cin >> aux.name >> aux.region >> aux.distance;
			v.pb(aux);
		}
		sort(v.begin(), v.end(), cmp);
		rep(i, 0, Q) cout << v[i].name << '\n';
	}
	
	
		
	return 0;
}
