// Author: Gustavo Policarpo
// Name: Digits
// Level: 5
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2867

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
	
    int T; cin >> T;
    while(T--){
    	int N, M; cin >> N >> M;
    	//log(N^M) = M*log(N)
    	cout << int(M*log10(N)+1) << '\n';
	}
	

	return 0;
} 
