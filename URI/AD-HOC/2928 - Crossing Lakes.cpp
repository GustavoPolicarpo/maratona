// Author: Gustavo Policarpo
// Name: Crossing Lakes
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2928

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;


int main(){

	int n; cin >> n;
	char mat[n+2][100];
	rep(i, 0, n) cin >> mat[i];
	mat[n][0]='-';
	mat[n+1][0]='-';
	
	int ans = 0;
	rep(i, 0, n){
		if(mat[i][0]=='.' && mat[i+1][0]=='.' && mat[i+2][0]=='.'){
			puts("N");
			return 0;
		}
		if(mat[i][0]=='.'){
			ans++;
			while(mat[i+1][0]=='.') i++;
		}
	}
	
	cout << ans << '\n';
			
	return 0;
}
