// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Escolha Difícil
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2702

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

typedef long long int ll;
typedef pair < int, int > ii;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int v[3][3], ans = 0;
	rep(i, 0, 2) rep(j, 0, 3) cin >> v[i][j];
	rep(i, 0, 3) ans+=(max(0, v[1][i]-v[0][i]));
	
	cout << ans << '\n';

	return 0;
	
}
