// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Bactérias
// Nível: 5
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1422

#include <bits/stdc++.h>
 
#define INF 0x3F3F3F3F
#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back
#define pi 3.1415926535897932384626433832795028841971
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) printf("%d ", x[i][j]); printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define MAXV 1010000
#define F first
#define S second
#define EPS 1e-9
#define mk make_pair
 
using namespace std;
 
typedef pair <int, int> ii;
typedef long long int ll;
typedef unsigned long long int ull;

#define mod 13371337
const int TAM = 4;
struct Matriz{
	ull mat[TAM][TAM];
};

Matriz identidade; ull N;

Matriz multiplica(Matriz A, Matriz B)
{
	Matriz C;
	rep(i, 0, TAM)
		rep(j, 0, TAM){
			C.mat[i][j]=0;
			rep(k, 0, TAM)
				C.mat[i][j]=((C.mat[i][j]%mod+((A.mat[i][k]%mod)*(B.mat[k][j]%mod))%mod));
		}
	return C;
			
}

Matriz fastExp(Matriz base, ull p)
{
	if(p==0) return identidade;
	Matriz ret=fastExp(base, p/2);
	ret=multiplica(ret, ret);
	if(p&1) ret=multiplica(ret, base);
	return ret;
}

int main(){
	//freopen("out.txt", "w", stdout);

	int z=1;
	
	identidade.mat[0][0]=1, identidade.mat[0][1]=0, 
	identidade.mat[0][2]=0, identidade.mat[0][3]=0,
	identidade.mat[1][0]=0, identidade.mat[1][1]=1, 
	identidade.mat[1][2]=0, identidade.mat[1][3]=0,
	identidade.mat[2][0]=0, identidade.mat[2][1]=0, 
	identidade.mat[2][2]=1, identidade.mat[2][3]=0,
	identidade.mat[3][0]=0, identidade.mat[3][1]=0, 
	identidade.mat[3][2]=0, identidade.mat[3][3]=1;
	
	while(cin >> N){ 
		if(N==0) break;
	
	ull in[4][1];
		rep(i, 0, 4) cin >> in[i][0];
		
	Matriz base;
		base.mat[0][0]=1, base.mat[0][1]=1, 
		base.mat[0][2]=1, base.mat[0][3]=1,
		base.mat[1][0]=1, base.mat[1][1]=0, 
		base.mat[1][2]=0, base.mat[1][3]=0,
		base.mat[2][0]=0, base.mat[2][1]=1, 
		base.mat[2][2]=0, base.mat[2][3]=0,
		base.mat[3][0]=0, base.mat[3][1]=0, 
		base.mat[3][2]=1, base.mat[3][3]=0;
		base=fastExp(base, N-3);
		
		//printf("Case %d: %llu %lld %lld\n", z++, N, mod, (2*base.mat[0][0]-1)%mod);		
		//cout << "Case " << z++ << ": ";
		ull out=((base.mat[0][0]*in[3][0])%mod + (base.mat[0][1]*in[2][0])%mod + 
			(base.mat[0][2]*in[1][0])%mod + (base.mat[0][3]*in[0][0])%mod)%mod;
		cout << out << '\n';
	}
	
return 0;
}

