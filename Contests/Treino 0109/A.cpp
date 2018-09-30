#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int main(){
	
	int T; cin >> T;
	while(T--){
		ll a, b; scanf("%lld %lld", &a, &b);
		ll gc = __gcd(a, b);
		if(gc-1) puts("Sim");
		else puts("Nao");
	}

	return 0;
} 
