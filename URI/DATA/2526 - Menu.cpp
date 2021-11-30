// Author: Gustavo Policarpo
// Name: Menu
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2526

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ll, ii > iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;

ll BIT[1000010][2], n;
void update(int x, int v, int op){ 
    while(x <= n){ 
        BIT[x][op] += v; 
        x += x&-x; 
    } 
} 
ll query(int x, int op){ 
    ll ans = 0; 
    while(x > 0){ 
        ans += BIT[x][op]; 
        x -= x&-x; 
    } 
    return ans; 
}

ll vec[1000010], pro[1000010];
int main(){
	
	while(scanf("%lld", &n) !=EOF){
		
		rep(i, 1, n+1){
			scanf("%lld", &vec[i]);
			rep(j, 0, 2){
				BIT[i][j]=0;
			}	pro[i]=0;
		}
		
		for(int i=n; i>=1; i--){
			ll aux=query(vec[i]-1, 0);
			update(vec[i], 1, 0);
			pro[i]=aux;
		}
		
		ll ans=0;
		for(ll i=n; i>=1; i--){
			ll aux=query(vec[i]-1, 1);
			update(vec[i], pro[i], 1);
			ans+=aux;
		}
		
		printf("%lld\n", ans);
		
	}
	
	return 0;
	
}
