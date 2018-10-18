// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Números de Sorte
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2855

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

vector <int> v[2];

int main(){
    
    int n, m;
    while(scanf("%d", &n)!=EOF){ int aux;
    	v[0].clear(), v[1].clear();
    	rep(i, 0, n) scanf("%d", &aux), v[0].pb(aux);
    	scanf("%d", &m); int s = 2, yep = 1;
    	while(42){
    		//rep(i, 0, v[0].size()) cout << v[0][i] << " "; puts("\n");
    		if(s>v[0].size() || v[0][s-1]>m) break;
    		v[1].clear();
    		rep(j, 0, v[0].size()){
    			if((j+1)%s==0){
    				if(v[0][j]==m){
    					yep = 0;
    					break;
					}
				}else{
					v[1].pb(v[0][j]);	
				}
			}
			if(!yep) break;
			swap(v[0], v[1]);
			s++;
		}
		if(yep) puts("Y");
		else puts("N");
	}
	
    return 0;
}  
