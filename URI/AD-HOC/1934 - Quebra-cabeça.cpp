// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Quebra-cabeça
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1934

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

	int L, C;
	scanf("%d %d", &L, &C);
	
	map <string, int> ml[L], mc[C], mapa;
	map<string, int> :: iterator it;
	
	int sl[L], sc[C];
	string in[L][C];
	
	rep(i, 0, L){
		rep(j, 0, C){
			cin >> in[i][j];
			ml[i][in[i][j]]++;
			mc[j][in[i][j]]++;
		}
		cin >> sl[i];
	}	rep(j, 0, C){
			cin >> sc[j];
		}
		
	while(42){
		int fim = 1;
		rep(i, 0, L){
			rep(j, 0, C){
				if(mapa.count(in[i][j])){
					if(ml[i].count(in[i][j])){
						sl[i]-=mapa[in[i][j]]*ml[i][in[i][j]];
						ml[i].erase(in[i][j]);
					}
					if(mc[j].count(in[i][j])){
						sc[j]-=mapa[in[i][j]]*mc[j][in[i][j]];
						mc[j].erase(in[i][j]);
					}
				}
			}
		}
		
		rep(i, 0, L){
			if(ml[i].size()==1){
				rep(j, 0, C){
					if(ml[i].count(in[i][j])){
						mapa[in[i][j]] = sl[i]/ml[i][in[i][j]];
						fim = 0;
						break;
					}
				}
			}
		}
		
		rep(j, 0, C){
			if(mc[j].size()==1){
				rep(i, 0, L){
					if(mc[j].count(in[i][j])){
						mapa[in[i][j]] = sc[j]/mc[j][in[i][j]];
						fim = 0;
						break;
					}
				}
			}
		}
		
		if(fim) break;
		
	}
	
	for(it=mapa.begin(); it!=mapa.end(); it++){
		cout << it->first << " " << it->second << '\n';
	}
	
	
	
	
	return 0;
}
