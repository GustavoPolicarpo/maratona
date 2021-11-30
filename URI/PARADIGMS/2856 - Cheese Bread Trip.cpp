// Author: Gustavo Policarpo
// Name: Cheese Bread Trip
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2856

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, ii> iii;

int N, R;
struct use{
	int x, y, z;
	char zz;
};
use in[1010];
int dp[10][1010];

int main(){
    
	cin >> N >> R;
	rep(i, 0, N){
		cin >> in[i].x >> in[i].zz >> in[i].y;
		if(in[i].zz=='G') in[i].z = 0;
		if(in[i].zz=='B') in[i].z = 1;
		if(in[i].zz=='C') in[i].z = 2;
	}
	
	int ans = 0;
	rep(z, 0, 7){
		memset(dp[z], -1, sizeof dp[z]); dp[z][0] = 0;
		rep(i, 0, N){
			for(int j=R; j>=in[i].y; j--){
				if(!(z&(1<<in[i].z)) || dp[z][j-in[i].y]==-1) continue;
				dp[z][j] = max(dp[z][j], dp[z][j-in[i].y]+in[i].x);
				ans = max(ans, dp[z][j]);
			}
		}
	}
	
	cout << ans << '\n';
	
	
	
    return 0;
}  
