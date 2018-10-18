// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Festival de Estátuas de Gelo
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1034

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;


int vis[1000010];
int N, M, a[25];

int solve(){
	rep(i, 0, M+1) vis[i] = 0;
	queue <ii> q;
	rep(i, 0, N) q.push(ii(a[i], 1)), vis[a[i]] = 1;
	while(!q.empty()){
		int m = q.front().F, t = q.front().S; q.pop();
		if(m==M) return t;
		rep(i, 0, N){
			int mm = m+a[i];
			if(mm>M || vis[mm]) continue;
			vis[mm] = t+1;
			q.push(ii(mm, vis[mm]));
		}
	}
}

int main(){
	
	
	int T; scanf("%d", &T);
	while(T--){
		scanf("%d %d", &N, &M);
		rep(i, 0, N) scanf("%d", &a[i]);
		printf("%d\n", solve());
	}
	
	
	return 0;
}  
