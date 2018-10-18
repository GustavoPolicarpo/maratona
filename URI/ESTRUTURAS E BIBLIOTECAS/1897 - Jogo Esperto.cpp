// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jogo Esperto
// Nível: 4
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1897

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


int main()
{
	int N, M;
	cin >> N >> M;
	set <int> vis;
	int k=0, aux=N;
	queue <ii> q;
	q.push(mp(aux,0));
	
	while(q.front().F!=M){
		
		aux=q.front().F;
		k=q.front().S;
		//cout << aux << " " << k << endl;
		q.pop();
		
		if(vis.count(aux)) continue;
		
		vis.insert(aux);
		q.push(mp(aux*2,k+1));
		q.push(mp(aux*3,k+1));
		q.push(mp(aux/2,k+1));
		q.push(mp(aux/3,k+1));
		q.push(mp(aux+7,k+1));
		q.push(mp(aux-7,k+1));
	}
	cout << k << endl;
	
return 0;
}
