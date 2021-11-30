// Author: Gustavo Policarpo
// Name: Espertofone
// Level: 9
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1584

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
const int mod=1e9+7;

struct Matriz{
	ll mat[30][30];
};

Matriz identidade, grafo; 
int N, L; ll K;

Matriz multiplica(Matriz A, Matriz B)
{
	Matriz C;
	rep(i, 0, L)
		rep(j, 0, L){
			C.mat[i][j]=0;
			rep(k, 0, L)
				C.mat[i][j]=((C.mat[i][j]%mod+((A.mat[i][k]%mod)*(B.mat[k][j]%mod))%mod));
		}
	return C;			
}

Matriz fastExp(Matriz base, ll p)
{
	if(p==0) return identidade;	
	Matriz ret=fastExp(base, p/2);
	ret=multiplica(ret, ret);
	if(p&1) ret=multiplica(ret, base);
	return ret;
}

bool dentro(int x, int y){
	return x>=0 && x<N && y>=0 && y<N;
}

int x[]={1, 2, 3, 4, 5};
bool block(int i, int j, int m, int n, int k, int l){
	int dx=m-i, dy=n-j;
	rep(z, 0, 5){
		int ax=m+dx*x[z], ay=n+dy*x[z];
		if(dentro(ax, ay) && ax==k && ay==l) return true;
	}
	return false;
}

int main(){
	
	rep(i, 0, 30) identidade.mat[i][i]=1;
	
	while( scanf("%d %lld", &N, &K) !=EOF ){
		
		map<ii, int> C; int cnt=0;
		
		rep(i, 0, N)
		rep(j, 0, N)
			C[mp(i, j)]=cnt++;
		
		
		rep(i, 0, N)
		rep(j, 0, N)
		rep(k, 0, N)
		rep(l, 0, N){
			int a=C[mp(i, j)], b=C[mp(k, l)];
			if(a==b){
				grafo.mat[a][b]=0;
				continue;
			}
			
			int yep=1;
			
			rep(m, 0, N)
			rep(n, 0, N){
				int c=C[mp(m, n)];
				if(a==c || b==c) continue;
				if(block(i, j, m, n, k, l))
					yep=0;
			}
			
			grafo.mat[a][b]=yep;
			
		}
		
		L=cnt;
		grafo=fastExp(grafo, K);
		
		/*rep(i, 0, L){
			rep(j, 0 , L)
				cout << grafo.mat[i][j] << " ";
			cout << '\n';
		}*/
		
		ll ans=0;
		
		rep(i, 0, L) rep(j, 0, L){
			ans+=grafo.mat[i][j];
			if(ans>=mod) ans%=mod;
		}
		
		cout << ans << '\n';
		
	}
	
	
	return 0;
	
}
