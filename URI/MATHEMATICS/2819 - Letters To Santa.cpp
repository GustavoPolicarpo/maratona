// Author: Gustavo Policarpo
// Name: Letters To Santa
// Level: 5
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2819

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int T;
ll mat[26][26], id[26][26], tmp[26][26];
int N, C, Q, mod = 1e9+7;

void multiply(ll m1[][26], ll m2[][26]) {
    memset( tmp, 0, sizeof(tmp) );
    for( int a = 0; a < N; ++a ){
        for( int b = 0; b < N; ++b ){
            for( int c = 0; c < N; ++c ){
                tmp[a][b] += ( m1[a][c] * m2[c][b] )%mod;
            }
            tmp[a][b] = ( tmp[a][b] )%mod;
        }
    }
    memcpy( m1, tmp, sizeof tmp );
} 

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	scanf("%d", &T);
	while(T--){
		scanf("%d %d %d", &C, &N, &Q);
		char bloc[2];
		rep(i, 0, N) rep(j, 0, N) mat[i][j] = 1, id[i][j] = (i==j ? 1 : 0);
		
		rep(i, 0, Q){
			scanf("%s", bloc);
			mat[bloc[0]-'a'][bloc[1]-'a'] = 0;
		}
		
		C--;
		while(C){
			if(C&1) multiply(id, mat);
			multiply(mat, mat), C>>=1;
		}
		
		ll ans = 0;
		rep(i, 0, N){
			rep(j, 0, N){
				//cout << id[i][j] << " ";
				ans += id[i][j];
			}
			//cout << "\n";
		}
		
		printf("%lld\n", ans%mod);
		
	}
	

	return 0;
}
