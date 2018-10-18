// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Mapas de Karnaugh I
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2051

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




int dx[]={1, 2, -1, 20};

int main(){
	
	int T; cin >> T;
	
	rep(z, 0, T){
		
		int N, x=0, y=0; cin >> N; string s; cin.ignore();
		
		int mat[4][4], fim=2;
		if(N==4) fim=4;
		
		
		rep(i, 0, pow(2, N)){
			
			getline(cin, s); int p=s.size()-1, v;
			while(!isdigit(s[p])) p--; v=s[p]-'0';
			mat[x][y]=v;
			
			if(N==4) x+=dx[i%4];
			else x++;
			
			if(x>=fim){
				x=0;
				y++;
				if(y==2) y=3;
				if(y==4) y=2;
			}
			
		}
		
		/*rep(i, 0, N){
			rep(j, 0, N)
				cout << mat[i][j];
			cout << '\n';
		}*/
		
		if(z) puts("");
		puts("Mapa de Karnaugh");
		
		if(N==2){
			puts("  0 1");
			cout << "0|";
			rep(i, 0, 2){
				if(i) cout << " ";
				cout << mat[0][i];
			}	cout << '\n';
			cout << "1|";
			rep(i, 0, 2){
				if(i) cout << " ";
				cout << mat[1][i];
			}	cout << '\n';
		}
		
		else if(N==3){
			puts("  00 01 11 10");
			cout << "0|";
			rep(i, 0, 4){
				if(i) cout << "  ";
				cout << mat[0][i];
			}	cout << '\n';
			cout << "1|";
			rep(i, 0, 4){
				if(i) cout << "  ";
				cout << mat[1][i];
			}	cout << '\n';
		}
		
		else{
			puts("   00 01 11 10");
			cout << "00|";
			rep(i, 0, 4){
				if(i) cout << "  ";
				cout << mat[0][i];
			}	cout << '\n';
			cout << "01|";
			rep(i, 0, 4){
				if(i) cout << "  ";
				cout << mat[1][i];
			}	cout << '\n';
			cout << "11|";
			rep(i, 0, 4){
				if(i) cout << "  ";
				cout << mat[2][i];
			}	cout << '\n';
			cout << "10|";
			rep(i, 0, 4){
				if(i) cout << "  ";
				cout << mat[3][i];
			}	cout << '\n';
		}
		
		int v=1, f=1, a=N==2?2:4;
		
		rep(i, 0, fim){
			rep(j, 0, a){
				if(mat[i][j]) f=0;
				else v=0;
			}
		}
		
		if(v) puts("Tautologia");
		else if(f) puts("Contradicao");
		else puts("Contingencia");
		
	}
	
	return 0;
	
}
