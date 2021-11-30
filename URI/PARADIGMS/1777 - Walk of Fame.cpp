// Author: Gustavo Policarpo
// Name: Walk of Fame
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1777

#include <bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED
using namespace std;
#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define mp make_pair
#define F first
#define S second
#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;


bool my_sort(ii a, ii b){
	if(a.F!=b.F) return a.F<b.F;
	return a.S>b.S;
}
int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int T; cin >> T;
	
	rep(z, 1, T+1){
		int N, C, E, cnt=0;
		vector <ii> in, ans; ii aux;
		
		scanf("%d %d", &N, &C);
		rep(i,0,C){
			scanf("%d %d", &aux.F, &aux.S);
			in.pb(aux);
		}
		sort(in.begin(), in.end(), my_sort);
		
		aux=in[0];
		rep(i, 1, C){
			if(in[i].F > aux.S){
				swap(aux.F, aux.S);
				ans.pb(aux);
				aux=in[i];
			}
			else aux.S=max(aux.S, in[i].S);
		}	swap(aux.F, aux.S);
			ans.pb(aux);
		
		sort(ans.begin(), ans.end(), my_sort);
		
		//rep(i, 0, C) cout << ans[i].F << " " << ans[i].S << '\n';
		
		scanf("%d", &E);
		while(E--){
			scanf("%d", &aux.F);
			int p=lower_bound(ans.begin(), ans.end(), ii(aux.F, 0))-ans.begin();
			if(p==ans.size()) continue;
			if(ans[p].F >= aux.F && ans[p].S <=aux.F) cnt++;
		}
		
		printf("Caso #%d: %d\n", z, cnt);
	}
	
	
	return 0;
	
}
