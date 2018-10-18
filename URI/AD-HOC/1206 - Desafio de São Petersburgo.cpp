// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Desafio de São Petersburgo
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1206

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
typedef pair<int,int> ii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);



int main()
{
	
	//freopen("in.txt", "r", stdin);
	
	int N;
	while(cin >> N){
		int mat[8][8], atk[8][8];
		memset(atk, 0, sizeof atk);
		memset(mat, 0, sizeof mat);
		string op; vector <string> vin;
		
		rep(i, 0, N){
			cin >> op;
			vin.pb(op);
			int x = op[1]-'a', y = op[2]-'1';
			mat[y][x] = 2;
		}
		
		rep(i, 0, N){
			op = vin[i];
//			cout << op[2]-'1' << " " << op[1]-'a' << '\n';
			if(op[0]=='P'){
				int x = op[1]-'a', y = op[2]-'1';
				if(y && x){
					if(mat[y-1][x-1]==2) atk[y-1][x-1] = 1;
					else mat[y-1][x-1] = 1;
				}
				if(y && x<8){
					if(mat[y-1][x+1]==2) atk[y-1][x+1] = 1;
					else mat[y-1][x+1] = 1;
				}
			}else if(op[0]=='T'){
				int x = op[1]-'a', y = op[2]-'1';
				rep(k, 1, 10){
					if(x-k>=0){
						if(mat[y][x-k]==2){
							atk[y][x-k] = 1;
							break;
						}
						mat[y][x-k] = 1;
					}
				}
				rep(k, 1, 10){
					if(x+k<8){
						if(mat[y][x+k]==2){
							atk[y][x+k] = 1;
							break;
						}
						mat[y][x+k] = 1;
					}
				}
				rep(k, 1, 10){
					if(y-k>=0){
						if(mat[y-k][x]==2){
							atk[y-k][x] = 1;
							break;
						}
						mat[y-k][x] = 1;
					}
				}
				rep(k, 1, 10){
					if(y+k<8){
						if(mat[y+k][x]==2){
							atk[y+k][x] = 1;
							break;
						}
						mat[y+k][x] = 1;
					}
				}
				
			}else if(op[0]=='B'){
				int x = op[1]-'a', y = op[2]-'1';
				rep(k, 1, 16){
					if(x-k>=0 && y-k>=0){
						if(mat[y-k][x-k]==2){
							atk[y-k][x-k] = 1;
							break;
						}
						mat[y-k][x-k] = 1;
					}
				}
				rep(k, 1, 16){
					if(x+k<8 && y+k<8){
						if(mat[y+k][x+k]==2){
							atk[y+k][x+k] = 1;
							break;
						}
						mat[y+k][x+k] = 1;
					}
				}
				rep(k, 1, 16){
					if(y-k>=0 && x+k<8){
						if(mat[y-k][x+k]==2){
							atk[y-k][x+k] = 1;
							break;
						}
						mat[y-k][x+k] = 1;
					}
				}
				rep(k, 1, 16){
					if(y+k<8 && x-k>=0){
						if(mat[y+k][x-k]==2){
							atk[y+k][x-k] = 1;
							break;
						}
						mat[y+k][x-k] = 1;
					}
				}
			}else if(op[0]=='R'){
				int x = op[1]-'a', y = op[2]-'1';
				rep(k, 1, 16){
					if(x-k>=0 && y-k>=0){
						if(mat[y-k][x-k]==2){
							atk[y-k][x-k] = 1;
							break;
						}
						mat[y-k][x-k] = 1;
					}
				}
				rep(k, 1, 16){
					if(x+k<8 && y+k<8){
						if(mat[y+k][x+k]==2){
							atk[y+k][x+k] = 1;
							break;
						}
						mat[y+k][x+k] = 1;
					}
				}
				rep(k, 1, 16){
					if(y-k>=0 && x+k<8){
						if(mat[y-k][x+k]==2){
							atk[y-k][x+k] = 1;
							break;
						}
						mat[y-k][x+k] = 1;
					}
				}
				rep(k, 1, 16){
					if(y+k<8 && x-k>=0){
						if(mat[y+k][x-k]==2){
							atk[y+k][x-k] = 1;
							break;
						}
						mat[y+k][x-k] = 1;
					}
				}
				rep(k, 1, 10){
					if(x-k>=0){
						if(mat[y][x-k]==2){
							atk[y][x-k] = 1;
							break;
						}
						mat[y][x-k] = 1;
					}
				}
				rep(k, 1, 10){
					if(x+k<8){
						if(mat[y][x+k]==2){
							atk[y][x+k] = 1;
							break;
						}
						mat[y][x+k] = 1;
					}
				}
				rep(k, 1, 10){
					if(y-k>=0){
						if(mat[y-k][x]==2){
							atk[y-k][x] = 1;
							break;
						}
						mat[y-k][x] = 1;
					}
				}
				rep(k, 1, 10){
					if(y+k<8){
						if(mat[y+k][x]==2){
							atk[y+k][x] = 1;
							break;
						}
						mat[y+k][x] = 1;
					}
				}
			}else if(op[0]=='W'){
				int x = op[1]-'a', y = op[2]-'1';
				rep(k, 1, 2){
					if(x-k>=0 && y-k>=0){
						if(mat[y-k][x-k]==2){
							atk[y-k][x-k] = 1;
							break;
						}
						mat[y-k][x-k] = 1;
					}
				}
				rep(k, 1, 2){
					if(x+k<8 && y+k<8){
						if(mat[y+k][x+k]==2){
							atk[y+k][x+k] = 1;
							break;
						}
						mat[y+k][x+k] = 1;
					}
				}
				rep(k, 1, 2){
					if(y-k>=0 && x+k<8){
						if(mat[y-k][x+k]==2){
							atk[y-k][x+k] = 1;
							break;
						}
						mat[y-k][x+k] = 1;
					}
				}
				rep(k, 1, 2){
					if(y+k<8 && x-k>=0){
						if(mat[y+k][x-k]==2){
							atk[y+k][x-k] = 1;
							break;
						}
						mat[y+k][x-k] = 1;
					}
				}
				rep(k, 1, 2){
					if(x-k>=0){
						if(mat[y][x-k]==2){
							atk[y][x-k] = 1;
							break;
						}
						mat[y][x-k] = 1;
					}
				}
				rep(k, 1, 2){
					if(x+k<8){
						if(mat[y][x+k]==2){
							atk[y][x+k] = 1;
							break;
						}
						mat[y][x+k] = 1;
					}
				}
				rep(k, 1, 2){
					if(y-k>=0){
						if(mat[y-k][x]==2){
							atk[y-k][x] = 1;
							break;
						}
						mat[y-k][x] = 1;
					}
				}
				rep(k, 1, 2){
					if(y+k<8){
						if(mat[y+k][x]==2){
							atk[y+k][x] = 1;
							break;
						}
						mat[y+k][x] = 1;
					}
				}
			}
		}
		/*rep(i, 0, 8){
			rep(j, 0, 8)
				cout << mat[i][j] << " ";
			cout << "\n";
		}*/
		int dx[]={-1, -1, -1, 0, 0, 1, 1, 1, 0},
			dy[]={-1, 0, 1, -1, 1, -1, 0, 1, 0};
		cin >> op;
		int x = op[1]-'a', y = op[2]-'1';
		//cout << y << " " << x << '\n';
		bool yep = true;
		rep(i, 0, 9){
			int ax = x+dy[i], ay = y+dx[i];
			if(ax>=0 && ay>=0 && ax<8 && ay<8){
				if(!mat[ay][ax] || (mat[ay][ax]==2 && !atk[ay][ax])){
					yep = false;
				}
					
			}
				
		}
		if(yep) puts("SIM");
		else puts("NAO");
		
	}


	return 0;
}

