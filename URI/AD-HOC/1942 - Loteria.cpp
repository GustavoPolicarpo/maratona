// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Loteria
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1942

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

const ll mod = 1e9+7;


int main(){
	
	int N, K; cin >> N >> K;
	vector <int> v[N]; int aux;
	
	rep(i, 0, N){
		rep(j, 0, K){
			scanf("%d", &aux);
			v[i].pb((aux&1));
		}
	}
	
	int ix = 0;
	rep(j, 0, K){
		rep(i, ix, N){
			if(v[i][j]&1){
				swap(v[i], v[ix]);
				ix++;
				break;
			}
		}
		rep(i, ix, N){
			if(v[i][j]&1){
				rep(k, j, K)
					v[i][k]^=v[ix-1][k];
			}
		}
	}
	
	int yep = 1;
	rep(i, 0, N){
		int cnt = 0;
		rep(j, 0, K){
			if(v[i][j]==0){
				cnt++;
			}
		}
		if(cnt==K){
			yep--;
			break;
		}
	}
	
	rep(i, 0, min(N, K)){
		if(v[i][i]!=1){
			yep++;
			break;
		}
	}
	
	yep ? puts("S") : puts("N");
		
	return 0;
}
