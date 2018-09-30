#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

const int MAXT = 1e9+10;
const int MAXS = sqrt(MAXT)+10;
const int MAXSS = sqrt(MAXS)+10;

vector <int> primos;
int eh[MAXS];

void crivo(){
	memset(eh, 1, sizeof eh);
	eh[0] = eh[1] = 0;
	for(int i=2; i<MAXSS; i++){
		if(eh[i]){
			for(int j=i*i; j<MAXS; j+=i)
				eh[j] = 0;
		}
	}
	for(int i=2; i<MAXS; i++){
		if(eh[i])
			primos.pb(i);
	}
}

ll solve(int n){
	ll ans = n;
	vector <int> fator, expoente;
	
	rep(i, 0, primos.size()){
		int cnt = 0;
		while(n%primos[i]==0){
			n/=primos[i];
			cnt++;
		}
		if(cnt){
			fator.pb(primos[i]);
			expoente.pb(cnt);
		}
	}
	if(n>1) fator.pb(n), expoente.pb(1);
	
	rep(i, 0, expoente.size()){
		if(expoente[i]%2!=0)
			ans = ans*fator[i];
	}
	
	return ans;
}

int main(){
	
	crivo();
	
	int T; cin >> T;
	rep(z, 1, T+1){
		int N; cin >> N;
		printf("Caso #%d: %lld\n", z, solve(N));
	}
	
	return 0;
} 
