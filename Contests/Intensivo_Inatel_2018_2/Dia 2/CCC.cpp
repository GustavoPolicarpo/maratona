#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

bool pd[101*501];
int n, v[101];

int main(){

	int T; cin >> T;
	while(T--){
		cin >> n; int sum = 0;
		rep(i, 0, n) cin >> v[i], sum+=v[i];
		
		memset(pd, false, sizeof pd);
		pd[0] = true;
		rep(i, 0, n){
			for(int j=sum; j>=v[i]; j--)
				pd[j]|=pd[j-v[i]];
		}
		
		int ans = 0x3f3f3f3f;
		rep(i, 0, sum+1){
			if(pd[i]==true){
				ans = min(ans, abs(sum-i-i));
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
} 
