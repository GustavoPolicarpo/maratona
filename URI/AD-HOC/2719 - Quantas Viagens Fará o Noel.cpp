// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Quantas Viagens Fará o Noel?
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2719

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
	int t; cin >> t;
	while(t--){
		
		int n, m; cin >> n >> m; int p[n];
		rep(i, 0, n) cin >> p[i];
		
		int ans = 1, aux = 0;
		rep(i, 0, n){
			if(aux+p[i]<=m) aux+=p[i];
			else aux = p[i], ans++;
		}
		
		cout << ans << '\n';
		
	}
	
	return 0;
	
}
