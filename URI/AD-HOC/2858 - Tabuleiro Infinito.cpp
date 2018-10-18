// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tabuleiro Infinito
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2858

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;

int vis[2000200];
int D, E;
void solve(){
	queue <ii> q;
	q.push(ii(1000000, 0)); vis[1000000] = 1;
	while(!q.empty()){
		int u = q.front().F, t = q.front().S; q.pop();
		if(u==1000000+1 || u==1000000-1){
			cout << t << '\n';
			return;
		}
		int uu;
		uu = u+D;
		if(uu<=2*1000000 && !vis[uu]){
			vis[uu] = 1;
			q.push(ii(uu, t+1));
		}
		uu = u-E;
		if(uu>=0 && !vis[uu]){
			vis[uu] = 1;
			q.push(ii(uu, t+1));
		}
	}
	cout << "IMPOSSIVEL" << '\n';
}

int main(){
    
    scanf("%d %d", &D, &E); if(D>E) swap(D, E);
	solve();
	
    return 0;
}  
