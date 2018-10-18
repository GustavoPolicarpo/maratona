// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Turistas no Parque Huacac...
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2708

#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define N 25000
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;
 



int main()
{
	
	string s;
	int cnt1 = 0, cnt2 = 0, in;
	while(cin >> s){
		if(s=="ABEND"){
			cout << cnt2 << '\n' << cnt1 << '\n';
			return 0;
		}
		cin >> in;
		if(s=="SALIDA"){
			cnt1++;
			cnt2+=in;
		}
		else if(s=="VUELTA"){
			cnt1--;
			cnt2-=in;
		}
	}
	
	
    return 0;
}
