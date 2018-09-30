#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int n, h[100010], v[100010];

int main(){

	scanf("%d", &n);
	rep(i, 0, n){
		scanf("%d", &h[i]);
		v[i] = h[i];
	}
	
	sort(v, v+n);
	
	int maior = -1, ans = -1;
	rep(i, 0, n){
		int p = lower_bound(v, v+n, h[i]) - v;
		if(p>maior){
			maior = p;
			ans = i;
		}
		else if(p==maior){
			ans = -1;
		}
	}
	
	cout << ans << 
	

	return 0;
} 
