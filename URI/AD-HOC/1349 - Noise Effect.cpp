// Author: Gustavo Policarpo
// Name: Noise Effect
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1349

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



int main(){
	
	int L;
	
	while(scanf("%d", &L) and L){
		
		int mat[L][L], tam[L][L], pat[L][L];
		
		rep(i, 0, L) rep(j, 0, L) scanf("%d", &mat[i][j]);
		rep(i, 0, L) rep(j, 0, L) scanf("%d", &pat[i][j]);
		
		double ans=0.0, qt;
		
		qt=0.0;
		rep(i, 0, L){
			rep(j, 0, L){
				if(abs(mat[i][j]-pat[i][j])<=100) qt++;
			}
		}
		
		ans=max(ans, qt/(L*L));
		
		rep(i, 0, L){
			rep(j, 0, L){
				tam[i][L-j-1]=mat[i][j];
			}
		}
		qt=0.0;
		rep(i, 0, L){
			rep(j, 0, L){
				if(abs(tam[i][j]-pat[i][j])<=100) qt++;
			}
		}
		
		ans=max(ans, qt/(L*L));
		
		/******************/
		rep(i, 0, L){
			rep(j, 0, L){
				tam[i][L-j-1]=mat[j][i];
			}
		}
		qt=0.0;
		rep(i, 0, L){
			rep(j, 0, L){
				if(abs(tam[i][j]-pat[i][j])<=100) qt++;
			}
		}
		
		ans=max(ans, qt/(L*L));
		
		rep(i, 0, L){
			rep(j, 0, L){
				mat[i][L-j-1]=tam[i][j];
			}
		}
		qt=0.0;
		rep(i, 0, L){
			rep(j, 0, L){
				if(abs(mat[i][j]-pat[i][j])<=100) qt++;
			}
		}
		
		ans=max(ans, qt/(L*L));
		
		/******************/
		rep(i, 0, L){
			rep(j, 0, L){
				mat[i][L-j-1]=tam[j][i];
			}
		}
		qt=0.0;
		rep(i, 0, L){
			rep(j, 0, L){
				if(abs(mat[i][j]-pat[i][j])<=100) qt++;
			}
		}
		
		ans=max(ans, qt/(L*L));
		
		rep(i, 0, L){
			rep(j, 0, L){
				tam[i][L-j-1]=mat[i][j];
			}
		}
		qt=0.0;
		rep(i, 0, L){
			rep(j, 0, L){
				if(abs(tam[i][j]-pat[i][j])<=100) qt++;
			}
		}
		
		ans=max(ans, qt/(L*L));
		
		/******************/
		rep(i, 0, L){
			rep(j, 0, L){
				tam[i][L-j-1]=mat[j][i];
			}
		}
		qt=0.0;
		rep(i, 0, L){
			rep(j, 0, L){
				if(abs(tam[i][j]-pat[i][j])<=100) qt++;
			}
		}
		
		ans=max(ans, qt/(L*L));
		
		rep(i, 0, L){
			rep(j, 0, L){
				mat[i][L-j-1]=tam[i][j];
			}
		}
		qt=0.0;
		rep(i, 0, L){
			rep(j, 0, L){
				if(abs(mat[i][j]-pat[i][j])<=100) qt++;
			}
		}
		
		ans=max(ans, qt/(L*L));
		
		printf("%.2lf\n", ans*100.0);
		
		
	}
	
	return 0;
	
}
