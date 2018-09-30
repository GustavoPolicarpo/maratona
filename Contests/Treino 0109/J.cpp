#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;


int main(){
	
	int n; cin >> n; iii v[n];
	
	rep(i, 0, n) cin >> v[i].F.F >> v[i].F.S >> v[i].S;
	rep(i, 0, n){
		rep(j, i+1, n){
			ll dst =  (v[i].F.F - v[j].F.F)*(v[i].F.F - v[j].F.F) + (v[i].F.S - v[j].F.S)*(v[i].F.S - v[j].F.S);
			if(dst==(v[i].S+v[j].S)*(v[i].S+v[j].S)) printf("%d %d\n", i+1, j+1);
		}
	}
	
	return 0;
} 
