// Author: Gustavo Policarpo
// Name: 13 Variables Derivative
// Level: 2
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2956

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

	double P, T; cin >> P >> T;
	printf("Concluimos que, dado o limite da entrada, a resposta seria:  y = f(x) = %.5lf.\n", P*T/2.0);
	
	return 0;
}
