// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Vila Natalina
// Nível: 1
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2725

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
typedef pair < int, ii > iii;


vector <iii> edg;
int N, K, pset[1010];

int findset(int x){
	if(x!=pset[x]) pset[x] = findset(pset[x]);
	return pset[x];
}

void unionset(int x, int y){
	x = findset(x), y = findset(y);
	pset[x] = y;
}

bool sameset(int x, int y){
	return findset(x) == findset(y);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T; cin >> T;
	
	while(T--){
		scanf("%d %d", &N, &K);
		vector <ii> in(N); ii aux;
		edg.clear();
		
		rep(i, 0, N){
			scanf("%d %d", &aux.F, &aux.S);
			in[i] = aux;
			pset[i] = i;
		}
		
		int u, v, c, dx, dy;
		rep(i, 0, N){
			rep(j, i+1, N){
				u = i, v = j, 
				dx = abs(in[i].F-in[j].F), dy = abs(in[i].S-in[j].S), 
				c = __gcd(dx, dy) - 1;
				edg.pb(iii(c, ii(u, v)));
			}
		}
		
		sort(edg.begin(), edg.end());
		
		ll mst = 0;
		rep(i, 0, edg.size()){
			u = edg[i].S.F,
			v = edg[i].S.S,
			c = edg[i].F;
			if(!sameset(u, v)){
				unionset(u, v);
				mst+=c;
			}
		}
		
		cout << mst*K << '\n';
		
	}
	
	return 0;
	
}
