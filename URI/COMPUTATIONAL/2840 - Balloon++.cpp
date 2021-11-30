// Author: Gustavo Policarpo
// Name: Balloon++
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2840

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
	
	int r, l; cin >> r >> l;
	int ans = (l)/(4.0/3.0*3.1415*r*r*r);
	cout << ans << '\n';
	
	return 0;
} 
