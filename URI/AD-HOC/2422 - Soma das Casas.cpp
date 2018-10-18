// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Soma das Casas
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2422

#include <bits/stdc++.h>

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
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;




int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n; cin >> n;
	int v[n], k;
	rep(i, 0, n) cin >> v[i];
	cin >> k;
	
	int i=0;
	while(i<n && v[i]<k){
		int p=lower_bound(v+i, v+n, k-v[i])-v;
		if(v[p]==k-v[i]){
			printf("%d %d\n", v[i], v[p]);
			return 0;
		}
		i++;
	}
	
	return 0;
	
}
