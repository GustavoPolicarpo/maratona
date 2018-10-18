// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tamanho da Placa
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2770

#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back

using namespace std;

int main(){
	int X, Y, M;
	while(cin >> X >> Y >> M){
		if(X>Y) swap(X, Y);
		int x, y;
		while(M--){
			cin >> x >> y;
			if(x>y) swap(x, y);
			if(x<=X && y<=Y) puts("Sim");
			else puts("Nao");
		}
	}
	return 0;
}
