// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Música Alta
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2814

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;



int main(){
	
	int n; cin >> n;
	int k, j;
	while(n--){
		cin >> k >> j;
		char mat[j][33]; ii a, b;
		rep(l, 0, j){
			scanf("%s", mat[l]);
			rep(c, 0, strlen(mat[l])){
				if(mat[l][c]=='F') a = ii(l, c);
				if(mat[l][c]=='J') b = ii(l, c);
			}
		}
		double dist = 10.0*sqrt((a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S));
		int val = (int)(dist);
		double den = 1;
		rep(i, 0, val) den = den*0.99;
		double ans = (double)k/den;
		ll resp = (ll)(ans);
		printf("%lld dBs\n", resp);
	}
			
	return 0;
}
