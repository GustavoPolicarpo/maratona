// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cidade no Centro
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2676

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
typedef pair<ii, int> iii;


const ll mod = 1000000007;


int main(){
	
	int N, R;
	
	while(scanf("%d %d", &N, &R)!=EOF){
		if(!N && !R) break;
		
		int mat[N+2][N+2]; memset(mat, 0x3f3f3f3f, sizeof mat); rep(i, 1, N+1) mat[i][i] = 0;
		
		int u, v, c;
		while(R--){
			scanf("%d %d %d", &u, &v, &c);
			if(mat[u][v] > c) mat[u][v] = mat[v][u] = c;
		}
		
		rep(k, 1, N+1)
		rep(i, 1, N+1)
		rep(j, 1, N+1)
			mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			
		int ans = 0x3f3f3f3f;
		rep(i, 1, N+1){
			int aux = 0;
			rep(j, 1, N+1)
				aux+=mat[i][j];
			if(aux < ans) ans = aux;
		}
		
		rep(i, 1, N+1){
			int aux = 0;
			rep(j, 1, N+1)
				aux+=mat[i][j];
			if(aux==ans)
				printf("%d ", i);
		}	printf("\n");
	}
				
	return 0;
}
