// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: RSA
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1716

#include <bits/stdc++.h>

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
typedef pair<ll,ll> ii;

ll eleva( ll b, int ex, int mod){
	ll ans = 1;
	for(; ex; ex>>=1){
		if( ex&1 ) ans = ( ans * b )%mod;
		b = ( b*b )%mod;
	}
	return ans;
}

bool isPrime(int n){
	if(n==2) return true;
	if(n%2==0) return false;
	int fim=sqrt(n);
	for(int i=3; i<=fim; i+=2) if(n%i==0) return false;
	return true;
}
int mdc(int  a, int b, int *x, int *y) {
  int xx, yy, d;
  if(b==0) {
    *x=1; *y=0;
    return a;
  }

  d = mdc(b, a%b, &xx, &yy);
  *x = yy;
  *y = xx - a/b*yy;
  return d;
}


int inverso(int a, int P){
  int x,y,d;
  d = mdc(a,P,&x,&y);

  if(x<0){
    x = x+P;
  }

  return x;
}

int main(){

	int N, E, C; cin >> N >> E >> C;
	
	int P=3, Q;
	for( ; P<sqrt(N)+1; P+=2 ){
		if(N%P==0 && isPrime(P)){
			Q=N/P;
			if(isPrime(Q)) break;
		}
	}
	
	int F=(P-1)*(Q-1);
	int D=inverso(E, F);
	int M=eleva(C, D, N);
	
	cout << M << '\n';
	
	return 0;
}
