// Author: Gustavo Policarpo
// Name: Party at the North Pole
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2845

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
	
	int n; cin >> n;
	int a[n], ans = 0; rep(i, 0, n) cin >> a[i], ans = max(ans, a[i]);
	cout << ans+1 << '\n';
	
	return 0;
} 
