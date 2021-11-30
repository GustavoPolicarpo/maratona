// Author: Gustavo Policarpo
// Name: Buffoon
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2963

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

	int N; scanf("%d", &N);
	int v0, v;
	
	scanf("%d", &v0);
	rep(i, 1, N){
		scanf("%d", &v);
		if(v>v0){
			puts("N");
			return 0;
		}
	}
	
	puts("S");
	
	return 0;
}
