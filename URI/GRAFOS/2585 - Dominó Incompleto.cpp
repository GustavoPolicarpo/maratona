// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Dominó Incompleto
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2585

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

#define INF 0x3f3f3f3f
const int mod=1e9+7;


ii n[66];
int N;


int dfs(int p, int l, ll mask){
	
	int ret=0, pc;
	if(l==0) pc=n[p].F;
	else pc=n[p].S;
	
	rep(i, 0, N){
		if(mask&(1LL<<i)) continue;
		if(n[i].F==pc) ret=max(ret, dfs(i, 1, mask|(1LL<<i)));
		else if(n[i].S==pc) ret=max(ret, dfs(i, 0, mask|(1LL<<i)));
	}
	
	return ret+1;
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	
	while(scanf("%d", &N) !=EOF){
		
		rep(i, 0, N){
			scanf("%d %d", &n[i].F, &n[i].S);
			if(n[i].F>n[i].S) swap(n[i].F, n[i].S);
		}
		
		int ans=0;
		rep(i, 0, N){
			ans=max(ans, dfs(i, 0, 1LL<<i));
			ans=max(ans, dfs(i, 1, 1LL<<i));
		}
		
		printf("%d\n", ans);
		
	}
	
		
	return 0;
	
}
