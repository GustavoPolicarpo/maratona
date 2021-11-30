// Author: Gustavo Policarpo
// Name: Maratona Brasileira de Po...
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2973

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

	int N, C, T, P[100010];
	scanf("%d %d %d", &N, &C, &T);
	rep(i, 0, N) scanf("%d", &P[i]);
	
	int ini = 1, fim = 1e9, mid, ans;
	while(ini<=fim){
		mid = (ini+fim)/2;
		ll aux = (ll)mid*T;
		int i = 0, j = 0;
		while(i<N && j<C){
			while(i<N && aux-P[i]>=0){
				aux-=P[i];
				i++;
			}
			aux = (ll)mid*T;
			j++;
		}
		if(i==N){
			ans = mid;
			fim = mid-1;
		}else{
			ini = mid+1;
		}
	}
	
	printf("%d\n", ans);
	
}
