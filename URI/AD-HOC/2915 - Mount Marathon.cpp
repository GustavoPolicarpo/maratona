// Author: Gustavo Policarpo
// Name: Mount Marathon
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2915

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
	
	int N; cin >> N;
	int C[N]; rep(i, 0, N) cin >> C[i];
	
	int ans = 0;
	for(int i=N-1; i>=0; i--){
		while(i && C[i-1]>=C[i]){
			i--;
		}
		ans++;
	}
	
	cout << ans << '\n';
	
	

	return 0;
} 
