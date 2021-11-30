// Author: Gustavo Policarpo
// Name: Rodoido
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2629

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define INF 0x3F3F3F3F3F

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

struct Matriz{
	double mat[6][6];
};

Matriz identidade; int L;

Matriz multiplica(Matriz A, Matriz B){
	Matriz C;
	rep(i, 0, L)
		rep(j, 0, L){
			C.mat[i][j]=0;
			rep(k, 0, L)
				C.mat[i][j]=((C.mat[i][j]+((A.mat[i][k])*(B.mat[k][j]))));
		}
	return C;
			
}

Matriz fastExp(Matriz base, int p){
	if(p==0) return identidade;
	Matriz ret=fastExp(base, p/2);
	ret=multiplica(ret, ret);
	if(p&1) ret=multiplica(ret, base);
	return ret;
}

int main()
{
	rep(i, 0, 6) identidade.mat[i][i] = 1.0;
	while(scanf("%d", &L)!=EOF){
		
		Matriz in;
		rep(i, 0, L) rep(j, 0, L) scanf("%lf", &in.mat[i][j]);
		
		int Q; scanf("%d", &Q);
		
		int i, j, k;
		while(Q--){
			scanf("%d %d %d", &i, &j, &k); i--, j--;
			Matriz aux;
			rep(i, 0, L) rep(j, 0, L) aux.mat[i][j] = in.mat[i][j];
			aux = fastExp(aux, k);
			printf("%.6lf\n", aux.mat[j][i]);
		}
		
		
	}
	
			
return 0;
}
