// Author: Gustavo Policarpo
// Name: The Coins of Robbie
// Level: 9
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2709

#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;
 


bool isPrime(int n){
	if(n<2) return false;
	rep(i, 2, sqrt(n)+1) if(n%i==0) return false;
	return true;
}

int main()
{
	
	int M;
	while(cin >> M){
		int v[M]; rep(i, 0, M) cin >> v[i];
		reverse(v, v+M);
		int N; cin >> N;
		int sum = 0; for(int i=0; i<M; i+=N) sum+=v[i];
		!isPrime(sum) ? puts("Bad boy! I’ll hit you.") : puts("You’re a coastal aircraft, Robbie, a large silver aircraft.");
	}
	
	
    return 0;
}
