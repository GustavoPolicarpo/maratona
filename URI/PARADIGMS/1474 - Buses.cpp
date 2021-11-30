// Author: Gustavo Policarpo
// Name: Buses
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1474

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

ll N, K, L;
const int mod=1000000;
struct Matriz{
	ull mat[2][2];
};

Matriz identidade; 

Matriz multiplica(Matriz A, Matriz B)
{
	Matriz C;
	rep(i, 0, 2)
		rep(j, 0, 2){
			C.mat[i][j]=0;
			rep(k, 0, 2)
				C.mat[i][j]=((C.mat[i][j]%mod+((A.mat[i][k]%mod)*(B.mat[k][j]%mod))%mod))%mod;
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

int main()
{
	identidade.mat[0][1]=0, identidade.mat[1][0]=0; 
	rep(i, 0, 2) identidade.mat[i][i]=1;
	while(scanf("%llu %llu %llu", &N, &K, &L) !=EOF){
		K%=mod, L%=mod;
		Matriz base; ull n=N/5;
		base.mat[0][0]=0, base.mat[0][1]=L, 
		base.mat[1][0]=1, base.mat[1][1]=K;
		base=fastExp(base, n);
		ull out=(base.mat[0][0]*1+base.mat[1][0]*K%mod)%mod;
		printf("%.6lld\n", out)	;
	}

return 0;
}
