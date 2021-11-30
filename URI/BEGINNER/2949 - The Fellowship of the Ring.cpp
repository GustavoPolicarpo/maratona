// Author: Gustavo Policarpo
// Name: The Fellowship of the Ring
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2949

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

int N, A, E, H, M, X;
string S; char O;

int main(){
	
	cin >> N;
	rep(i, 0, N){
		cin >> S >> O;
		if(O == 'X'){
			X++;	
		}
		if(O == 'M'){
			M++;
		}
		if(O == 'H'){
			H++;
		}
		if(O == 'E'){
			E++;
		}
		if(O == 'A'){
			A++;
		}
	}
	
	printf("%d Hobbit(s)\n", X);
	printf("%d Humano(s)\n", H);
	printf("%d Elfo(s)\n", E);
	printf("%d Anao(s)\n", A);
	printf("%d Mago(s)\n", M);
	
		
	return 0;
}
