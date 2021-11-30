// Author: Gustavo Policarpo
// Name: Hour for a Run
// Level: 5
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2968

#include <bits/stdc++.h>

// boca-submit-run teammgmu19 GGZBKdXEx PP C++14 FF

#define rep(i, a, b) for(int i = a; i < b; i++)
#define REP(i, a, b) rep(i, a, b+1)
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a, b) cout << #a << " = "  << a << " ---- " << #b << " = " << b << endl;
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int main(){

	int V, N; cin >> V >> N;
	rep(i, 1, 10){
		if(i-1) printf(" ");
		printf("%d", (V*N*i+9)/10);
	}	printf("\n");
	
	return 0;
}
