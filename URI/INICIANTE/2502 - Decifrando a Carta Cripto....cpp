// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Decifrando a Carta Cripto...
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2502

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)

typedef long long int ll;
typedef unsigned long long int ull;

const ull mod = 1e9+7;
const ull MAX = mod*mod*2;

void scanint(ull &x){
    register ull ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}


int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int C, N; string a, b; map <char, char> mapa;
	
	while(scanf("%d %d ", &C, &N) !=EOF){
		
		mapa.clear();
		getline(cin, b), getline(cin, a);
		rep(i, 0, a.size()){
			mapa[toupper(a[i])]=toupper(b[i]);
			mapa[tolower(a[i])]=tolower(b[i]);
			mapa[toupper(b[i])]=toupper(a[i]);
			mapa[tolower(b[i])]=tolower(a[i]);
		}
		
		rep(i, 0, N){
			getline(cin, a);
			rep(j, 0, a.size()){
				if(mapa.count(a[j])) cout << mapa[a[j]];
				else cout << a[j];
			}
			cout << '\n';
		}	cout << '\n';
	}
	
	return 0;
	
}
