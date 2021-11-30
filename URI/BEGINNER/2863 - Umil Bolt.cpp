// Author: Gustavo Policarpo
// Name: Umil Bolt
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2863

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int main(){
	
	int T;
	while(cin >> T){
	    double v[T];
	    rep(i, 0, T) cin >> v[i];
	    sort(v, v+T);
	    cout << fixed << setprecision(2) << v[0] << '\n';
	}
	

	return 0;
} 
