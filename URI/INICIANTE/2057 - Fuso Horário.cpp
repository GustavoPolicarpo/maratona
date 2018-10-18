// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fuso Horário
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2057

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;


int main()
{
	int S, T, F;
	cin >> S >> T >> F;
	int aux=S+T+F;
	if(aux>=24)
		aux-=24;
	else if(aux<0)
		aux+=24;
	cout << aux << endl;

return (0);
}

