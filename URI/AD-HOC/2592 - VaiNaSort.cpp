// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: VaiNaSort
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2592

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


int main(){

	int N, aux;
	
	while(scanf("%d", &N) and N){
		
		rep(z, 1, INF){
			
			int yep=1;
			rep(i, 1, N+1){
				scanf("%d", &aux);
				if(aux!=i) yep=0;
			}
			
			if(yep){
				printf("%d\n", z);
				break;
			}
			
		}
		
	}
	
	return 0;
	
}
