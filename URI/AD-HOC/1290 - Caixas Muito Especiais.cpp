// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Caixas Muito Especiais
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1290

#pragma comment(linker, "/stack:200000000")                                     
#pragma GCC optimize("Ofast")                                                   
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")   
#define _CRT_SECURE_NO_WARNINGS          

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


int main(){

	int N, M;
	while(scanf("%d %d", &N, &M)!=EOF){
		
		if(!N) break;
		vector <int> n;
		vector <int> aux; 
		map <vector <int> , int> mapa;
		map <vector <int>, int> :: iterator it;
		
		int xua;
		
		rep(i, 0, 3){
			scanf("%d", &xua);
			n.pb(xua);
		}
		sort(n.begin(), n.end());
		
		rep(i, 0, M){
			aux.clear();
			rep(j, 0, 3){
				scanf("%d", &xua);
				aux.pb(xua);
			}
			sort(aux.begin(), aux.end());
			mapa[aux]++;
		}
		
		int ans = 0x3f3f3f3f;
		
		for(it = mapa.begin(); it!=mapa.end(); it++){
			aux = it->first, xua = it->second;
			if(xua>=N){
				int vn = n[0]*n[1]*n[2];
				int va = aux[0]*aux[1]*aux[2];
				int yep = 1;
				rep(j, 0, 3){
					if(n[j]>aux[j]){
						yep = 0;
						break;
					}
				}
				//cout << vn << " " << va << '\n';
				if(yep){
					ans = min(ans, va-vn);
				}
			}
		}
			
		if(ans==0x3f3f3f3f) puts("impossible");
		else cout << ans << '\n';
		
	}
	
	return 0;
}
