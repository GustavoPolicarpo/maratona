// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Folha de Pagamentos
// Nível: 4
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2680

#include<bits/stdc++.h>
#define gc getchar
 
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
typedef pair<int, ii> iii;

void scanint(int &x){
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

const ll mod = 1000000007;

vector <int> primos;
int eh[10010];

void crivo(){
	memset(eh, 1, sizeof eh); eh[0] = eh[1] = 0;
	for(int i = 2; i<= 1000; i++) if(eh[i]) for(int j=i*i; j<=10000; j+=i) eh[j] = 0;
	rep(i, 0, 10000) if(eh[i]) primos.pb(i);
}

ll mypow(int b, int e){
	ll ret = 1; rep(i, 0, e) ret*=b;
	return ret;
}

ll solve(int n){
	vector <int> div, fat; int i = 0;
	while(n>1 && i<primos.size()){
		if(n%primos[i]==0){
			div.pb(primos[i]); int cnt = 0;
			while(n%primos[i]==0) n/=primos[i], cnt++;
			fat.pb(cnt);
		}
		i++;
	}
	if(n>1) div.pb(n), fat.pb(1);
	ll ans = 1;
	rep(i, 0, div.size()) ans *= ( (mypow(div[i], fat[i]+1)-1)/(div[i]-1) );
	return ans;
}

int main(){
	
	crivo();
	int N, n; scanint(N);
	
	while(N--){
		scanint(n);
		printf("%lld\n", solve(n));
	}
				
	return 0;
}
