// Author: Gustavo Policarpo
// Name: Unlock the Smartphone
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1687

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
typedef pair<ii, int> iii;

#define INF 0x3f3f3f3f
const ll mod=1LL << 30, modF=1300031;

struct Matriz{
	ll mat[15*15+2][15*15+2];
};

Matriz identidade, grafo; 
int N, L, LN, K, LK;

Matriz multiplica(Matriz A, Matriz B)
{
	Matriz C;
	rep(i, 0, L) rep(j, 0, L/2+1){
		C.mat[i][j]=0;
		rep(k, 0, L){
			C.mat[i][j]=(C.mat[i][j]+A.mat[i][k]*B.mat[k][j]);
			if(C.mat[i][j] >= mod) C.mat[i][j]%=modF;
		}
		C.mat[L-i-1][L-j-1]=C.mat[i][j];
		//C.mat[i][L-j-1]=C.mat[i][j];
		//C.mat[L-i-1][j]=C.mat[i][j];
	}
	/*rep(i, 0, L){
		cout << A.mat[i][0] << " ";
	}
	cout << '\n';
	rep(i, 0, L){
		cout << A.mat[L-i-1][L-1] << " ";
	}
	cout << "aa\n\n";*/
	return C;			
}

Matriz fastExp(Matriz base, int p){
	Matriz ret=identidade;
	while(p){
		if(p&1) ret=multiplica(ret, base);
		p>>=1;
		base=multiplica(base, base);
	}
	return ret;
}

int main(){
	
	vector <iii> vin;
	rep(i, 0, 15*15+2) identidade.mat[i][i]=1;
	
	int cnt=0;
	while( scanf("%d %d", &N, &K) !=EOF ){
		
		if(!N) break;
		vin.pb(iii(ii(N, K), cnt++));
			
	}
	
	vector <ll> saida(cnt, 0);
	sort(vin.begin(), vin.end());
	
	rep(z, 0, vin.size()){
		N=vin[z].F.F, K=vin[z].F.S, cnt=vin[z].S, L=N*N;
		
		if(N!=LN){
			rep(i, 0, N)
			rep(j, 0, N)
			rep(k, 0, N)
			rep(l, 0, N){
				int a=(N*i)+j, b=(N*k)+l;
				if(a==b){
					grafo.mat[a][b]=0;
					continue;
				}
				
				int yep=1;
				int dx=abs(k-i), dy=abs(l-j);
				if(__gcd(dx, dy) > 1) yep=0;
				
				grafo.mat[a][b]=yep;
			}
			LK=0;
		}
		
		K=K-LK;	
		grafo=fastExp(grafo, K-1);
		
		rep(i, 0, L) rep(j, 0, L){
			saida[cnt]+=grafo.mat[i][j];	
			if(saida[cnt]>=mod) saida[cnt]%=modF;
		}
	}
	
	rep(i, 0, saida.size()) printf("%lld\n", saida[i]%modF);
	
		
	return 0;	
}
