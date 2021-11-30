// Author: Gustavo Policarpo
// Name: Fibonacci Again!
// Level: 10
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1531

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define INF 0x3F3F3F3F3F

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

const int MAXN = 2;
int mod, vet[10000001];
 
ll mat[MAXN][MAXN];
ll ans[MAXN][MAXN];
ll tmp[MAXN][MAXN];
ll M[MAXN][MAXN][MAXN];

void multiply(ll m1[][MAXN], ll m2[][MAXN]) {
    memset( tmp, 0, sizeof(tmp) );
    for( int a = 0; a < MAXN; ++a ){
        for( int b = 0; b < MAXN; ++b ){
            for( int c = 0; c < MAXN; ++c ){
                tmp[a][b] += ( m1[a][c] * m2[c][b] )%mod;
            }
            tmp[a][b] = ( tmp[a][b] )%mod;
        }
    }
    memcpy( m1, tmp, sizeof tmp );
} 

int main()
{  
    int N;
	while(scanf("%d %d", &N, &mod) !=EOF){
		
		int x, aux; 
		x=2, vet[0]=1, vet[1]=1;
		while(1){
			vet[x]=( vet[x-1]%mod + vet[x-2]%mod )%mod;
			if(vet[x]%mod==1 && vet[x-1]%mod==1) break;
			x++;
		} 
		aux=mod, mod=x-1;
                
        ans[0][0] = ans[1][1] = 1;
        mat[0][0] = 1, mat[0][1] = 1, mat[1][0] = 1;
        ans[0][1] = ans[1][0] = mat[1][1] = 0;
        
        while( N ){
            if( N&1 ) multiply( ans, mat );
            N >>= 1;
            multiply( mat, mat );
        }
        
        N=ans[0][1]; mod=aux;
        
        ans[0][0] = ans[1][1] = 1;
        mat[0][0] = 1, mat[0][1] = 1, mat[1][0] = 1;
        ans[0][1] = ans[1][0] = mat[1][1] = 0;
        
        while( N ){
            if( N&1 ) multiply( ans, mat );
            N >>= 1;
            multiply( mat, mat );
        }
    
        printf("%lld\n", ans[0][1]);
            
    }
            
return 0;
}
