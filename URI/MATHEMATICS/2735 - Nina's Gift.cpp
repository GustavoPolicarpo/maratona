// Author: Gustavo Policarpo
// Name: Nina's Gift
// Level: 8
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2735

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;


/*

2 0 1 4 3

0 1 2 3 4
2 0 1 4 3
1 2 0 3 4
0 1 2 4 3

*/

int party[100010];
int party_size[100010];
int pos_party[100010];
int P[100010], T, N, Q, J, K, tam, cnt, ans;

void dfs(int u, int c, int p){
	if(party[u]!=-1) return;
	party[u] = c, pos_party[u] = p++, tam++;
	dfs(P[u], c, p);
}

int main(){

	scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		rep(i, 0, N){
			scanf("%d", &P[i]);	
			party[i] = -1;
		}	cnt = 1;	
		
		rep(i, 0, N){
			if(party[i]==-1){
				tam = 0;
				dfs(i, cnt, 0);
				party_size[cnt] = tam;
				cnt++;
			}
		}
		
		//rep(i, 0, N) printf("%d %d %d\n", i, party[i], pos_party[i]);
		
		scanf("%d", &Q);
		while(Q--){
			scanf("%d %d", &J, &K);
			K = (J+K)%N;
			if(party[J]!=party[K]) puts("-1");
			else{
				ans = pos_party[J] - pos_party[K];
				while(ans<0) ans+=party_size[party[J]];
				printf("%d\n", ans);
			}
		}
	}
	
	return 0;
}
