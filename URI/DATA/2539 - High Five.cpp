// Author: Gustavo Policarpo
// Name: High Five
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2539

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


const int MAXV = 100010;
int in[MAXV], BIT[MAXV], n, cv[MAXV];

void update(int x, int v){ 
    while(x <= n){ 
        BIT[x] += v; 
        x += x&-x; 
    } 
} 
  
int query(int x){ 
    int ans = 0; 
    while(x > 0){ 
        ans += BIT[x]; 
        x -= x&-x; 
    } 
    return ans; 
}


int main(){
	
	while(scanf("%d", &n) !=EOF){
		
		rep(i, 0, n+2) BIT[i]=0;
		
		rep(i, 1, n+1){
			scanf("%d", &in[i]);
			cv[in[i]]=i;
			update(in[i], 1);
		}
		
		ll ans=0;
		rep(i, 1, n+1){
			ans+=query(n)-query(cv[i]);
			update(cv[i], -1);
		}
		
		printf("%lld\n", ans);
		
	}
	
	
	return 0;
	
}
