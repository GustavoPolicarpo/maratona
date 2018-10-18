// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Indecisão das Renas
// Nível: 3
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2721

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
typedef unsigned long long int ull;
typedef pair < int, int > ii;



int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	string s[]={"Dasher", "Dancer", "Prancer", "Vixen", "Comet", "Cupid", "Donner", "Blitzen", "Rudolph"};
	int v[9], sum = 0;
	rep(i, 0, 9) cin >> v[i], sum+=v[i];
	sum = (sum+8)%9;
	
	cout << s[sum] << '\n';
	
	return 0;
	
}
