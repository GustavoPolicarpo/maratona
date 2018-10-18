// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fofão da Pérsia
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2042

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F33
#define limite 10000005

struct salto{
	int feels, custo;
};
typedef pair < int, salto > ii;
typedef long long int ll;

int N, M, P, D, B; 
ll pd[101][1001];
vector <ii> adj[101];

ll solve(int bairro, int sola)
{
	if(bairro==D) return 0;
	if(pd[bairro][sola]!=-1) return pd[bairro][sola];
	ll ret=-INF;
	rep(i, 0, adj[bairro].size()){
		salto aux = adj[bairro][i].second;
		if(sola-aux.custo<0) continue;
		ret=max(ret, solve(adj[bairro][i].first, sola-aux.custo)+aux.feels);
	}
	return pd[bairro][sola]=ret;	
}

int main ()
{
	scanf("%d %d %d %d %d", &N, &M, &P, &D, &B);
	salto aux; int a, b;
	rep(i, 0, M){
		scanf("%d %d %d %d", &a, &b, &aux.feels, &aux.custo);
		adj[a].pb(mp(b, aux));
		adj[b].pb(mp(a, aux));
	}
	memset(pd, -1, sizeof pd);
	ll out=0;
	out = max(out, solve(P, B));
	if(out==0) printf("-1\n");
	else       cout << out << endl;
			
return 0;
}
