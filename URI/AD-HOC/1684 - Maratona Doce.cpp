// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Maratona Doce
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1684

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int grau[10010];
int N, M, u, v;

bool check(){
	rep(i, 0, N) if(grau[i]&1) return false;
	return true;
}

int main()
{

	int T; cin >> T;
	while(T--){
		scanf("%d %d", &N, &M);
		rep(i, 0, N) grau[i] = 0;
		rep(i, 0, M){
			scanf("%d %d", &u, &v);
			grau[u]++, grau[v]++;
		}
		check() ? puts("Yes") : puts("No");
	}

	return 0;
	
}
