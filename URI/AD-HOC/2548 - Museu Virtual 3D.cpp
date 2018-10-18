// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Museu Virtual 3D
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2548

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;


int main(){
	
	int n, m;
	while(scanf("%d %d", &n, &m)!=EOF){
		int v[n];
		rep(i, 0, n) scanf("%d", &v[i]);
		sort(v, v+n); reverse(v, v+n);
		int ans=0;
		rep(i, 0, m) ans+=v[i];
		cout << ans << '\n';
	}
	
	return 0;
	
}
