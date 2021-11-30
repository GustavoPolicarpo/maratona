// Author: Gustavo Policarpo
// Name: Alien Charts
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2921

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


ll L, C, pd[1010], mat[1010][1010];
ll Kadane2D(){
	ll ret = -1LL<<56;
	rep(left, 0, C){
		rep(i, 0, L) pd[i] = 0;
		rep(right, left, C){
			rep(i, 0, L) pd[i] += mat[i][right];
			ll sum = 0;
			rep(i, 0, L){
				sum += pd[i];
				if(sum>ret)
				ret=sum;
				if(sum < 0) sum = 0;
			}
		}
	}
	return ret;
}

int main(){
	
	while(scanf("%lld", &L)!=EOF){
		C = L;
		rep(i, 0, L) rep(j, 0, C){
			scanf("%lld", &mat[i][j]);
		}
		cout << Kadane2D() << '\n';
		
	}	
	
	

	return 0;
} 
