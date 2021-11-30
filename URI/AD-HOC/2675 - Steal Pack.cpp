// Author: Gustavo Policarpo
// Name: Steal Pack
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2675

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


int main(){
	
	int N;
	while(scanf("%d", &N) !=EOF){
		ll ans = 0; int n[N];
		rep(i, 0, N) scanint(n[i]);
		int mesa = n[N-1];
		for(int i=N-2; i>=0; i--){
			if(n[i]<mesa) mesa = n[i];
			else ans+=n[i];
		}
		printf("%lld\n", ans);
	}	
	
				
	return 0;
}
