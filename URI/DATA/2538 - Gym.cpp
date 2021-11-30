// Author: Gustavo Policarpo
// Name: Gym
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2538

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
int BIT[MAXV], IP, M, PC, NA;

void update(int x, int v){ 
    while(x <= MAXV-5){ 
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
	
	while(scanf("%d %d", &IP, &M) !=EOF){
		
		memset(BIT, 0, sizeof BIT);
		
		int ans=0;
		rep(i, 0, M){
			scanf("%d %d", &PC, &NA);
			int ini=max(0, PC-IP-1), fim=min(MAXV-5, PC+IP);
			int qt=query(fim)-query(ini);
			if(qt<=NA){
				update(PC, 1);
				ans++;
			}
		}
		
		printf("%d\n", ans);
		
	}
	
	
	return 0;
	
}
