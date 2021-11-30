// Author: Gustavo Policarpo
// Name: Tutors
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2120

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
typedef pair <int, int> ii;
typedef long long int ll;

struct use{
	int val, pai;
	ii esp;
	bool operator < (use aux) const{
		if(aux.pai==-2){
			return aux.val > esp.S;
		}else{
			if( esp.F != aux.esp.F )
				return esp.F < aux.esp.F;
			if( esp.S != aux.esp.S )
				return esp.S < aux.esp.S;
			if( val != aux.val )
				return val < aux.val;
		}
	}
};

int N, Q;
set <use> st;
set <use> :: iterator it;
int in[100010];
map<int, int> pai;

int main(){
	
	scanf("%d", &N);
	int x; use aux, go;
	rep(i, 0, N){
		scanf("%d", &x); in[i] = x;
		
		if(i==0){
			st.insert(use{x, -1, ii(1, 1000000000)});
		}else{
			it = st.lower_bound(use{x, -2});
			aux = *it; st.erase(it);
			go.pai = aux.val, go.val = x;
			if(go.val > aux.val){
				go.esp = ii(aux.val+1, aux.esp.S);
				aux.esp.S = aux.val-1;
			}else{
				go.esp = ii(aux.esp.F, aux.val-1);
				aux.esp.F = aux.val+1;
			}
			st.insert(go);
			st.insert(aux);
		}
	}
	
	for(auto xx : st){
		pai[xx.val]	= xx.pai;
	}
	
	scanf("%d", &Q);
	rep(i, 0, Q){
		if(i) printf(" ");
		scanf("%d", &x);
		printf("%d", pai[in[x-1]]);
	}	printf("\n");
	

	return 0;
}
