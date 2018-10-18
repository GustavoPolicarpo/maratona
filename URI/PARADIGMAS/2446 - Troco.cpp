// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Troco
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2446

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3f3f3f3f

typedef long long int ll;
typedef pair < int, int > ii;


//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


bool solve(int valor, int n, int *v){
	
	vector <int> al(valor+1, 0);
	vector <int> cheguei;
	al[0]=1;
	cheguei.pb(0);
	sort(v, v+n);
	
	for(int i=0; i<n&v[i]<=valor; i++){
		int fim=cheguei.size();
		rep(j, 0, fim){
			int vv=cheguei[j];
			int k=v[i]+vv;
			if(k==valor) return true;
			if(k>valor || al[k]) continue;
			al[k]=1;
			cheguei.pb(k);
		}

	}
	
	return false;
}

int main()
{
	int V, M;
	scanf("%d %d", &V, &M); int n[M];
	rep(i, 0, M) scanf("%d", &n[i]);
	
	solve(V, M, n) ? puts("S") : puts("N");

	return 0;
	
}
