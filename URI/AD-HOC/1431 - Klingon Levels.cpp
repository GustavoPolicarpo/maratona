// Author: Gustavo Policarpo
// Name: Klingon Levels
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1431

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
	
	int N;
	while(scanf("%d", &N) and N){
		vector <int> n[N]; int pos[N], qn[N];
		rep(i, 0, N){
			n[i].clear(), pos[i] = 0, qn[i] = 0;
			scanf("%d", &qn[i]); int aux;
			rep(j, 0, qn[i]){
				scanf("%d", &aux);
				n[i].pb(aux);
			}
			sort(n[i].begin(), n[i].end());
		}
		
		int ans = 0x3f3f3f3f;
		rep(T, 0, 1001){
			int aux = 0;
			rep(i, 0, N){
				while(pos[i]<qn[i] && n[i][pos[i]]<T) pos[i]++;
				int bs = pos[i];
				int av = qn[i] - bs;
				aux += abs(bs - av);
			}
			ans = min(ans, aux);
		}
		
		printf("%d\n", ans);
		
		
	}


	return 0;
}
