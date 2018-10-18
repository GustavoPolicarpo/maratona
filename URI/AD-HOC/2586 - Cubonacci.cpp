// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cubonacci
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2586

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


ll mat[3][3][3], aux[3][3][3];
int dir[]={-1, 0, 1};

bool dentro(int x, int y, int z){
	return x>=0&&y>=0&&z>=0&&x<3&&y<3&&z<3;	
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	
	int T; cin >> T;
	
	while(T--){
		
		int N; cin >> N;
		
		rep(i, 0, 3) rep(j, 0, 3) rep(k, 0, 3) cin >> mat[i][j][k];
		
		while(N--){
			
			rep(i, 0, 3)
			rep(j, 0, 3)
			rep(k, 0, 3){
				aux[i][j][k]=0;
				rep(a, 0, 3)
				rep(b, 0, 3)
				rep(c, 0, 3){
					int x=i+dir[a], y=j+dir[b], z=k+dir[c];
					if(dentro(x, y, z)) aux[i][j][k]+=mat[x][y][z];
				}
			}
			
			rep(i, 0, 3)
			rep(j, 0, 3)
			rep(k, 0, 3){
				mat[i][j][k]=aux[i][j][k];
			}
			
		}
		
		rep(i, 0, 3)
		rep(j, 0, 3){
			rep(k, 0, 3){
				if(k) cout << " ";
				cout << mat[i][j][k];
			}
			cout << '\n';
		}
		
	}
	
		
	return 0;
	
}
