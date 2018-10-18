// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: 2048
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1559

#define gc getchar_unlocked
#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main()
{
	int T; cin >> T;
	while(T--){
		int mat[4][4];
		bool yep, fim=false; vector <string> out;
		rep(i, 0, 4)
		rep(j, 0, 4){
			cin >> mat[i][j];
			if(mat[i][j]==2048) fim=true;
		}
		
		if(fim){
			puts("NONE");
			continue;
		}
		
		//teste DOWN
		yep=false;	
		rep(i, 0, 3){
			rep(j, 0, 4){
				if(mat[i][j]==0) continue;
				if(mat[i+1][j]==mat[i][j] || mat[i+1][j]==0){
					yep=true;
					break;
				}
			}
			if(yep) break;
		} if(yep) out.pb("DOWN");
		
		//teste LEFT
		yep=false;
		rep(i, 0, 4){
			rep(j, 1, 4){
				if(mat[i][j]==0) continue;
				if(mat[i][j-1]==mat[i][j] || mat[i][j-1]==0){
					yep=true;
					break;
				}
			}
			if(yep) break;
		} if(yep) out.pb("LEFT");
		
		//teste RIGHT
		yep=false;
		rep(i, 0, 4){
			rep(j, 0, 3){
				if(mat[i][j]==0) continue;
				if(mat[i][j+1]==mat[i][j] || mat[i][j+1]==0){
					yep=true;
					break;
				}
			}
			if(yep) break;
		} if(yep) out.pb("RIGHT");
		
		//teste UP
		yep=false;	
		rep(i, 1, 4){
			rep(j, 0, 4){
				if(mat[i][j]==0) continue;
				if(mat[i-1][j]==mat[i][j] || mat[i-1][j]==0){
					yep=true;
					break;
				}
			}
			if(yep) break;
		} if(yep) out.pb("UP");
		
		if(out.size()==0) cout << "NONE";
		else{
			rep(i, 0, out.size()){
				if(i>0) printf(" ");
				cout << out[i];
			}
		}
		cout << '\n';
		
	}

return 0;
}

