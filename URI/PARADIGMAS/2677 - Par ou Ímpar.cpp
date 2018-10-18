// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Par ou Ímpar
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2677

#include<bits/stdc++.h>
#define gc getchar
 
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
typedef pair<int, ii> iii;

void scanint(int &x){
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

const ll mod = 1000000007;

int N, pd[1001], mat[1001][3], aux[1001][3];

int main(){
	
	
	while(1){
		scanint(N); if(!N) break; N*=2;
		
		rep(i, 0, N){
			scanint(pd[i]);
			pd[i]&1 ? pd[i] = 0 : pd[i] = 1;
		}

		if(N==2){
			printf("%d\n", max(pd[0], pd[1]));
			continue;
		}
		
		mat[0][0]=pd[0];
		mat[1][1]=pd[1];
		mat[0][1]=max(pd[0], pd[1]);
			
		for(int j=2; j<N; j++){
			mat[j][2]=pd[j];
			mat[j-1][2]=max(pd[j-1], pd[j]);

			for(int i=j-2; i>=0; i--){	
				aux[i][2]=pd[j]+min(mat[i][0], mat[i+1][1]);
				mat[i][2]=pd[i]+min(mat[i+2][2], mat[i+1][1]);
				mat[i][2]=max(mat[i][2], aux[i][2]);
			}

			rep(i, 0, N){
				mat[i][0]=mat[i][1];
				mat[i][1]=mat[i][2];
			}
			
		}
		
		printf("%d\n", max(mat[0][2], N/2-mat[0][2]));
	}	
	
				
	return 0;
}
