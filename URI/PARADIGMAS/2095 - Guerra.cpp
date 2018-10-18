// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Guerra
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2095

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

#define INF 0x3f3f3f3f
#define mod 100000007
int hn[100010], hq[100010];

int main(){
	
	int s;
	while( scanf("%d", &s) != EOF ){
		int cnt = 0;
		rep(i,0,s) scanf("%d", &hq[i]);
		rep(i,0,s) scanf("%d", &hn[i]);
		sort(hq, hq+s); sort(hn, hn+s);
		rep(i,0,s) if( hn[i] > hq[cnt] ) cnt++;
		printf("%d\n", cnt);
	}
	
	return 0;
}
