#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


ll a[100010], b[100010], c[100010];

int main(){
	
	int n; scanf("%d", &n);
	rep(i, 0, n) scanf("%lld", &a[i]);
	rep(i, 0, n) scanf("%lld", &b[i]);
	rep(i, 0, n) scanf("%lld", &c[i]);
	
	ll ab = 0, ac = 0;
	rep(i, 0, n){
		ab = ab + (a[i]-b[i])*(a[i]-b[i]);
		ac = ac + (a[i]-c[i])*(a[i]-c[i]);
	}
	
	if(ab<=ac) puts("Yan");
	else puts("MaratonIME");
	
	return 0;
} 
